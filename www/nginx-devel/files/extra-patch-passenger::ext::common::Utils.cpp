--- ../passenger-3.0.1/ext/common/Utils.cpp.orig	2010-12-12 04:49:20.000000000 +0300
+++ ../passenger-3.0.1/ext/common/Utils.cpp	2010-12-12 04:54:51.000000000 +0300
@@ -837,7 +837,19 @@
 		sigaction(SIGFPE, &action, NULL);
 		sigaction(SIGABRT, &action, NULL);
 		
-		DIR *dir = opendir("/dev/fd");
+		DIR *dir = NULL;
+		#ifdef __APPLE__
+			dir = opendir("/dev/fd");
+		#else
+			struct stat dirbuf1,dirbuf2;
+			if (stat("/dev", &dirbuf1) == -1
+				|| stat("/dev/fd", &dirbuf2) == -1) {
+				_exit(1);
+			}
+			if (dirbuf1.st_dev != dirbuf2.st_dev) {
+				dir = opendir("/dev/fd");
+			}
+		#endif
 		if (dir == NULL) {
 			dir = opendir("/proc/self/fd");
 			if (dir == NULL) {
