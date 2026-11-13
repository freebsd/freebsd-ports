--- src/core/ItemAtt.cpp.orig	2024-11-06 19:10:17 UTC
+++ src/core/ItemAtt.cpp
@@ -691,19 +691,19 @@ bool CItemAtt::DeSerializePlainText(const std::vector<
       }
 
 #ifdef PWS_BIG_ENDIAN
-    unsigned char buf[len] = {0};
-        
     switch(type) {
       case ATTCTIME:
       case FILECTIME:
       case FILEMTIME:
       case FILEATIME:
-
-        memcpy(buf, &(*iter), len);
-        byteswap(buf, buf + len - 1);
-
-        if (!SetField(type, buf, len))
-          return false;
+        {
+          std::vector<char> buf(iter, iter+len);
+          unsigned char *begin = reinterpret_cast<unsigned char *>(buf.data());
+          unsigned char *end   = begin + len - 1;
+          byteswap(begin, end);
+          if (!SetField(type, begin, len))
+            return false;
+        }
         break;
 
       default:
