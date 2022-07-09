--- src/input/readers/raw/Raw.cc.orig	2022-07-05 21:26:56 UTC
+++ src/input/readers/raw/Raw.cc
@@ -36,6 +36,7 @@ Raw::Raw(ReaderFrontend* frontend)
 	firstrun = true;
 	mtime = 0;
 	ino = 0;
+	dev = 0;
 	forcekill = false;
 	offset = 0;
 	separator.assign((const char*)BifConst::InputRaw::record_separator->Bytes(),
@@ -280,12 +281,31 @@ bool Raw::OpenInput()
 	else
 		{
 		file = std::unique_ptr<FILE, int (*)(FILE*)>(fopen(fname.c_str(), "r"), fclose);
+		if ( ! file && Info().mode == MODE_STREAM )
+			{
+			// Watch /dev/null until the file appears
+			file = std::unique_ptr<FILE, int (*)(FILE*)>(fopen("/dev/null", "r"), fclose);
+			}
+
 		if ( ! file )
 			{
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
@@ -346,6 +366,7 @@ bool Raw::DoInit(const ReaderInfo& info, int num_field
 	fname = info.source;
 	mtime = 0;
 	ino = 0;
+	dev = 0;
 	execute = false;
 	firstrun = true;
 	int want_fields = 1;
@@ -574,23 +595,57 @@ bool Raw::DoUpdate()
 
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
 
+				break;
+
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
+				if ( sb.st_ino == ino && sb.st_dev == dev )
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
+					return false;
+					}
+				file.reset(nullptr);
+				file = std::unique_ptr<FILE, int (*)(FILE*)>(tfile, fclose);
+				ino = sb.st_ino;
+				dev = sb.st_dev;
+				offset = 0;
+				bufpos = 0;
 				break;
 
 			default:
