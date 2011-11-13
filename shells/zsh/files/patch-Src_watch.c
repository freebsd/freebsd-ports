--- Src/watch.c.orig	2011-11-13 10:39:47.736213000 +0100
+++ Src/watch.c	2011-11-13 10:47:22.110214518 +0100
@@ -30,8 +30,11 @@
 #include "zsh.mdh"
 
 /* Headers for utmp/utmpx structures */
-#ifdef HAVE_UTMP_H
+#if defined(HAVE_UTMP_H) && !defined(HAVE_UTMPX_H)
 # include <utmp.h>
+#else
+# undef HAVE_STRUCT_UTMP
+# undef HAVE_STRUCT_UTMP_UT_HOST
 #endif
 #ifdef HAVE_UTMPX_H
 # include <utmpx.h>
