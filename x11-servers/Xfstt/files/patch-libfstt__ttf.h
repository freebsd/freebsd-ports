--- libfstt/ttf.h.orig	Thu Aug  7 15:20:44 2003
+++ libfstt/ttf.h	Wed Sep  3 08:03:38 2003
@@ -49,10 +49,10 @@
 #endif
 
 #ifndef DEBUG
-#  define debug(format, ...)
+#  define debug(format, ARGS...)
 #  define STATIC static
 #else
-#  define debug(format, ...)	fprintf(outfile, format, ##__VA_ARGS__)
+#  define debug(format, ARGS...)	fprintf(outfile, format, ##ARGS)
 #  define STATIC
 #endif
 
