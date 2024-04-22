--- src/enc.c.orig	2023-12-13 20:01:11 UTC
+++ src/enc.c
@@ -17,6 +17,11 @@
 #include <xmlsec/xmlenc.h>
 #include <xmlsec/xmltree.h>
 
+// Backwards compatibility with xmlsec 1.2
+#ifndef XMLSEC_KEYINFO_FLAGS_LAX_KEY_SEARCH
+#define XMLSEC_KEYINFO_FLAGS_LAX_KEY_SEARCH 0x00008000
+#endif
+
 typedef struct {
     PyObject_HEAD
     xmlSecEncCtxPtr handle;
