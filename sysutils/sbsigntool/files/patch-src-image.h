--- src/image.h.orig	2015-01-15 19:43:49.000000000 +0100
+++ src/image.h	2015-01-15 19:49:04.000000000 +0100
@@ -34,6 +34,9 @@
 
 #include <stdint.h>
 
+#define	ATTRIBUTE_UNUSED __unused
+#define	ENUM_BITFIELD(X) enum X
+
 #include <bfd.h>
 #define DO_NOT_DEFINE_LINENO
 
