--- ./include/libbb.h.orig	2011-08-11 02:23:58.000000000 +0200
+++ ./include/libbb.h	2011-08-26 02:10:16.000000000 +0200
@@ -75,6 +75,9 @@
 #ifdef DMALLOC
 # include <dmalloc.h>
 #endif
+#ifndef HAVE_XTABS
+# define XTABS OXTABS
+#endif
 #include <pwd.h>
 #include <grp.h>
 #if ENABLE_FEATURE_SHADOWPASSWDS
@@ -120,9 +123,6 @@
 #ifndef HAVE_FDATASYNC
 # define fdatasync fsync
 #endif
-#ifndef HAVE_XTABS
-# define XTABS TAB3
-#endif
 
 
 /* Some libc's forget to declare these, do it ourself */
