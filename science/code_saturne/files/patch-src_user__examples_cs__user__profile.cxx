--- src/user_examples/cs_user_profile.cxx.orig	2023-06-20 20:09:20 UTC
+++ src/user_examples/cs_user_profile.cxx
@@ -38,7 +38,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)
+#include <dirent.h>
+#else
 #include <sys/dir.h>
+#endif
 #include <sys/stat.h>
 
 /*----------------------------------------------------------------------------
