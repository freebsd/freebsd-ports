--- ./include/platform.h.orig	2011-08-11 02:23:58.000000000 +0200
+++ ./include/platform.h	2011-08-26 02:10:16.000000000 +0200
@@ -417,6 +417,8 @@
 # undef HAVE_STRVERSCMP
 # undef HAVE_XTABS
 # undef HAVE_DPRINTF
+# undef HAVE_UNLOCKED_STDIO
+# undef HAVE_UNLOCKED_LINE_OPS
 #endif
 
 #if defined(__FreeBSD__)
