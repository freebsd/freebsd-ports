--- utils.h.orig	2022-10-29 19:34:27 UTC
+++ utils.h
@@ -16,4 +16,4 @@ char * format_value(double value, int digits_sig, int 
 #define min(x, y)	((x) < (y) ? (x) : (y))
 #define max(x, y)	((x) > (y) ? (x) : (y))
 
-void myusleep(useconds_t v);
+void myusleep(__useconds_t v);
