--- lpkit.h.orig	Sat Jun  7 14:25:47 2003
+++ lpkit.h	Sat Jun  7 14:30:27 2003
@@ -260,6 +260,7 @@
 #define MAX_WARN_COUNT 20
 
 #ifdef CHECK
+extern int	Warn_count;
 #define my_round(val, eps) { \
     REAL absv; \
         absv = ((val) < 0 ? -(val) : (val)); \
