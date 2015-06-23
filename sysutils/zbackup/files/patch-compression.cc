--- compression.cc.orig	2015-06-23 12:18:26.923826000 +0800
+++ compression.cc	2015-06-23 12:19:37.282685000 +0800
@@ -292,7 +292,7 @@
   }
 };
 
-#include <endian.h>
+#include <machine/endian.h>
 
 // like NoStreamEnDecoder, but also adds the uncompressed size before the stream
 //NOTE You should make sure that the compression function doesn't overwrite any
