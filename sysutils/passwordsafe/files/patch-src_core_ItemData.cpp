--- src/core/ItemData.cpp.orig	2022-04-25 06:47:08 UTC
+++ src/core/ItemData.cpp
@@ -1940,6 +1940,7 @@ bool CItemData::DeSerializePlainText(const std::vector
 
 #ifdef PWS_BIG_ENDIAN
-    unsigned char buf[len] = {0};
+    unsigned char buf[len];
+    memset(buf, 0, len*sizeof(char));
 
     switch(type) {
       case CTIME:
