--- src/mp4util.cpp.orig	2012-05-20 22:11:53 UTC
+++ src/mp4util.cpp
@@ -195,6 +195,9 @@ static bool convertBase64 (const char da
     return true;
 }
 
+}} // namespace mp4v2::impl
+
+extern "C"
 uint8_t *Base64ToBinary (const char *pData, uint32_t decodeSize, uint32_t *pDataSize)
 {
     uint8_t *ret;
@@ -208,7 +211,7 @@ uint8_t *Base64ToBinary (const char *pDa
     }
     size = (decodeSize * 3) / 4;
     groups = decodeSize / 4;
-    ret = (uint8_t *)MP4Calloc(size);
+    ret = (uint8_t *)mp4v2::impl::MP4Calloc(size);
     if (ret == NULL) return NULL;
     for (ix = 0; ix < groups; ix++) {
         uint8_t value[4];
@@ -220,7 +223,7 @@ uint8_t *Base64ToBinary (const char *pDa
                 }
                 size--;
                 value[jx] = 0;
-            } else if (convertBase64(pData[jx], &value[jx]) == false) {
+            } else if (mp4v2::impl::convertBase64(pData[jx], &value[jx]) == false) {
                 free(ret);
                 return NULL;
             }
@@ -234,6 +237,8 @@ uint8_t *Base64ToBinary (const char *pDa
     return ret;
 }
 
+namespace mp4v2 { namespace impl {
+
 // log2 of value, rounded up
 static uint8_t ilog2(uint64_t value)
 {
