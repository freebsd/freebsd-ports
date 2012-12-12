Index: include/aide.h
diff -u include/aide.h.orig include/aide.h
--- include/aide.h.orig	2010-08-09 02:39:31.000000000 +0900
+++ include/aide.h	2012-10-30 02:24:36.845508733 +0900
@@ -68,7 +68,7 @@
 # define HAVE_STRTOIMAX
 #endif
 
-#if SIZEOF_OFF64_T == SIZEOF_LONG_LONG
+#if AIDE_OFF_TYPE == off64_t && SIZEOF_OFF64_T == SIZEOF_LONG_LONG || AIDE_OFF_TYPE == off_t && SIZEOF_OFF_T == SIZEOF_LONG_LONG
 # ifdef HAVE_STRTOLL
 #  define AIDE_STRTOLL_FUNC strtoll
 # else
