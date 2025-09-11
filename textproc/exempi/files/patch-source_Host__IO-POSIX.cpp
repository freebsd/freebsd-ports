--- source/Host_IO-POSIX.cpp.orig	2023-12-24 09:37:15.000000000 -0800
+++ source/Host_IO-POSIX.cpp	2025-09-11 02:22:42.614150000 -0700
@@ -6,6 +6,8 @@
 // NOTICE: Adobe permits you to use, modify, and distribute this file in accordance with the terms
 // of the Adobe license agreement accompanying it. 
 // =================================================================================================
+
+#include <sys/param.h>
 
 #include "public/include/XMP_Environment.h"	// ! This must be the first include.
 
@@ -523,7 +525,13 @@
 	while ( true ) {
 		// Ignore all children with names starting in '.'. This covers ., .., .DS_Store, etc.
 		// ! On AIX readdir_r returns 9 instead of 0 for normal termination.
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1600000
+		int err = 0;
+		if ((result = readdir ( folder )) == NULL)	// ! Thread-safe form is not thread safe.
+			err = errno;
+#else
 		int err = readdir_r ( folder, childInfo, &result );	// ! Use the thread-safe form.
+#endif
 		if ( err == 9 ) return false;	// Tolerable should some other UNIX return 9.
 		if ( err != 0 ) XMP_Throw ( "Host_IO::GetNextChild, readdir_r failed", kXMPErr_ExternalFailure );
 		if ( result == 0 ) return false;
