--- ./include/libbb.h.orig	2012-07-02 14:08:25.000000000 +0000
+++ ./include/libbb.h	2012-07-17 02:08:37.000000000 +0000
@@ -51,6 +51,9 @@
 #include <termios.h>
 #include <time.h>
 #include <sys/param.h>
+#ifndef HAVE_XTABS
+# define XTABS OXTABS
+#endif
 #include <pwd.h>
 #include <grp.h>
 #if ENABLE_FEATURE_SHADOWPASSWDS
@@ -129,9 +132,6 @@
 #ifndef HAVE_FDATASYNC
 # define fdatasync fsync
 #endif
-#ifndef HAVE_XTABS
-# define XTABS TAB3
-#endif
 
 
 /* Some libc's forget to declare these, do it ourself */
