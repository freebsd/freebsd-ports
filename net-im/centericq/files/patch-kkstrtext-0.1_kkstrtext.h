--- kkstrtext-0.1/kkstrtext.h.orig	Wed Aug  9 10:50:49 2006
+++ kkstrtext-0.1/kkstrtext.h	Wed Aug  9 10:51:12 2006
@@ -87,7 +87,7 @@
     { \
 	va_list vgs__ap; char vgs__buf[1024]; \
 	va_start(vgs__ap, fmt); \
-	vsprintf(vgs__buf, fmt, vgs__ap); c = vgs__buf; \
+	vsnprintf(vgs__buf, sizeof(vgs__buf), fmt, vgs__ap); c = vgs__buf; \
 	va_end(vgs__ap); \
     }
 
