--- common.h.orig	2017-10-13 21:53:16 UTC
+++ common.h
@@ -28,7 +28,9 @@
 
 /* from string.h in glibc for Android/BSD */
 #ifndef strdupa
+# ifdef HAVE_ALLOCA_H
 # include <alloca.h>
+# endif
 # include <string.h>
 # define strdupa(s)                                                           \
     ({                                                                        \
@@ -40,7 +42,9 @@
 #endif
 
 #ifndef strndupa
+# ifdef HAVE_ALLOCA_H
 # include <alloca.h>
+# endif
 # include <string.h>
 # define strndupa(s, n)                                                       \
     ({                                                                        \
