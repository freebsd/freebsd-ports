--- src/input/readers/raw/Raw.cc.orig	2022-07-05 19:35:27 UTC
+++ src/input/readers/raw/Raw.cc
@@ -2,15 +2,15 @@
 
 #include "zeek/input/readers/raw/Raw.h"
 
-#include <errno.h>
 #include <fcntl.h>
-#include <signal.h>
-#include <stdio.h>
-#include <stdlib.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#include <cerrno>
+#include <csignal>
+#include <cstdio>
+#include <cstdlib>
 
 #include "zeek/input/readers/raw/Plugin.h"
 #include "zeek/input/readers/raw/raw.bif.h"
@@ -36,6 +36,7 @@ Raw::Raw(ReaderFrontend* frontend)
 	firstrun = true;
 	mtime = 0;
 	ino = 0;
+	dev = 0;
 	forcekill = false;
 	offset = 0;
 	separator.assign((const char*)BifConst::InputRaw::record_separator->Bytes(),
@@ -282,10 +283,27 @@ bool Raw::OpenInput()
 		file = std::unique_ptr<FILE, int (*)(FILE*)>(fopen(fname.c_str(), "r"), fclose);
 		if ( ! file )
 			{
+			if ( Info().mode == MODE_STREAM )
+				// Wait for file to appear
+				return true;
+
 			Error(Fmt("Init: cannot open %s", fname.c_str()));
 			return false;
 			}
 
+		if ( Info().mode == MODE_STREAM )
+			{
+			struct stat sb;
+			if ( fstat(fileno(file.get()), &sb) == -1 )
+				{
+				// This is unlikely to fail
+				Error(Fmt("Could not get fstat for %s", fname.c_str()));
+				return false;
+				}
+			ino = sb.st_ino;
+			dev = sb.st_dev;
+			}
+
 		if ( ! SetFDFlags(fileno(file.get()), F_SETFD, FD_CLOEXEC) )
 			Warning(Fmt("Init: cannot set close-on-exec for %s", fname.c_str()));
 		}
@@ -346,6 +364,7 @@ bool Raw::DoInit(const ReaderInfo& info, int num_field
 	fname = info.source;
 	mtime = 0;
 	ino = 0;
+	dev = 0;
 	execute = false;
 	firstrun = true;
 	int want_fields = 1;
@@ -574,25 +593,61 @@ bool Raw::DoUpdate()
 
 				mtime = sb.st_mtime;
 				ino = sb.st_ino;
+				dev = sb.st_dev;
 				// file changed. reread.
 				//
 				// fallthrough
 				}
 
 			case MODE_MANUAL:
-			case MODE_STREAM:
-				if ( Info().mode == MODE_STREAM && file )
-					{
-					clearerr(file.get()); // remove end of file evil bits
-					break;
-					}
-
 				CloseInput();
 				if ( ! OpenInput() )
 					return false;
 
 				break;
 
+			case MODE_STREAM:
+				// Clear possible EOF condition
+				if ( file )
+					clearerr(file.get());
+
+				// Done if reading from a pipe
+				if ( execute )
+					break;
+
+				// Check if the file has changed
+				struct stat sb;
+				if ( stat(fname.c_str(), &sb) == -1 )
+					// File was removed
+					break;
+
+				// Is it the same file?
+				if ( file && sb.st_ino == ino && sb.st_dev == dev )
+					break;
+
+				// File was replaced
+				FILE* tfile;
+				tfile = fopen(fname.c_str(), "r");
+				if ( ! tfile )
+					break;
+
+				// Stat newly opened file
+				if ( fstat(fileno(tfile), &sb) == -1 )
+					{
+					// This is unlikely to fail
+					Error(Fmt("Could not fstat %s", fname.c_str()));
+					fclose(tfile);
+					return false;
+					}
+				if ( file )
+					file.reset(nullptr);
+				file = std::unique_ptr<FILE, int (*)(FILE*)>(tfile, fclose);
+				ino = sb.st_ino;
+				dev = sb.st_dev;
+				offset = 0;
+				bufpos = 0;
+				break;
+
 			default:
 				assert(false);
 			}
@@ -604,6 +659,10 @@ bool Raw::DoUpdate()
 		{
 		if ( stdin_towrite > 0 )
 			WriteToStdin();
+
+		if ( ! file && Info().mode == MODE_STREAM )
+			// Wait for file to appear
+			break;
 
 		int64_t length = GetLine(file.get());
 		// printf("Read %lld bytes\n", length);
