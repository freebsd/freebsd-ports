[FDclone-users:00986]
--- mkmfsed.c.orig	2012-06-30 00:00:00.000000000 +0900
+++ mkmfsed.c	2012-07-16 19:12:29.375463265 +0900
@@ -193,7 +193,7 @@
 # if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
 	strappend(buf3, "-Wno-attributes");
 # endif
-# if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)
+# if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)
 	strappend(buf3, "-Wno-empty-body");
 # endif
 #endif	/* __GNUC__ && __GNUC_MINOR__ */
@@ -207,7 +207,7 @@
 #  if	H___GNUC__ > 4 || (H___GNUC__ == 4 && H___GNUC_MINOR__ >= 1)
 		strappend(buf1, "-Wno-attributes");
 #  endif
-#  if	H___GNUC__ > 4 || (H___GNUC__ == 4 && H___GNUC_MINOR__ >= 2)
+#  if	H___GNUC__ > 4 || (H___GNUC__ == 4 && H___GNUC_MINOR__ >= 3)
 		strappend(buf1, "-Wno-empty-body");
 #  endif
 # endif	/* H___GNUC__ && H___GNUC_MINOR__ */
