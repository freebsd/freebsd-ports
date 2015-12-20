--- include/libbb.h.orig	2015-10-24 00:24:35 UTC
+++ include/libbb.h
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
@@ -152,9 +155,6 @@
 #ifndef HAVE_FDATASYNC
 # define fdatasync fsync
 #endif
-#ifndef HAVE_XTABS
-# define XTABS TAB3
-#endif
 
 
 /* Some libc's forget to declare these, do it ourself */
