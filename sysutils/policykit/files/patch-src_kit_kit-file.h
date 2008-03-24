--- src/kit/kit-file.h.orig	2007-12-22 19:14:03.000000000 -0500
+++ src/kit/kit-file.h	2007-12-22 19:14:13.000000000 -0500
@@ -34,6 +34,7 @@
 #ifndef KIT_FILE_H
 #define KIT_FILE_H
 
+#include <sys/stat.h>
 #include <kit/kit.h>
 
 KIT_BEGIN_DECLS
