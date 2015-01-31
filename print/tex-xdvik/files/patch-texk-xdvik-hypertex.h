--- texk/xdvik/hypertex.h.orig	2013-05-04 22:32:56.000000000 +0900
+++ texk/xdvik/hypertex.h	2015-01-31 21:02:18.000000000 +0900
@@ -21,7 +21,7 @@
  */
 
 #ifndef HYPERTEX_H_
-#define HTEXTEX_H_
+#define HYPERTEX_H_
 
 /* fallbacks if parsing user-specified colors fails */
 #define LINK_COLOR_FALLBACK "BLUE2"
@@ -68,4 +68,4 @@
 
 extern Boolean htex_scan_anchor(const char *special, size_t len);
 
-#endif /* HTEXTEX_H_ */
+#endif /* HYPERTEX_H_ */
