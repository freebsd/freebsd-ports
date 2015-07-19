--- texk/xdvik/hypertex.h.orig	2004-05-07 22:10:22 UTC
+++ texk/xdvik/hypertex.h
@@ -21,7 +21,7 @@
  */
 
 #ifndef HYPERTEX_H_
-#define HTEXTEX_H_
+#define HYPERTEX_H_
 
 /* fallbacks if parsing user-specified colors fails */
 #define LINK_COLOR_FALLBACK "BLUE2"
@@ -68,4 +68,4 @@ extern void htex_forward(void);
 
 extern Boolean htex_scan_anchor(const char *special, size_t len);
 
-#endif /* HTEXTEX_H_ */
+#endif /* HYPERTEX_H_ */
