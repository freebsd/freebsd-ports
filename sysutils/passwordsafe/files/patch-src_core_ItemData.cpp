--- src/core/ItemData.cpp.orig	2024-11-06 19:10:17 UTC
+++ src/core/ItemData.cpp
@@ -2035,9 +2035,6 @@ bool CItemData::DeSerializePlainText(const std::vector
     }
 
 #ifdef PWS_BIG_ENDIAN
-    unsigned char buf[len];
-    memset(buf, 0, len*sizeof(buf[0]));
-	  
     switch(type) {
       case CTIME:
       case PMTIME:
@@ -2049,11 +2046,14 @@ bool CItemData::DeSerializePlainText(const std::vector
       case KBSHORTCUT:
       case XTIME_INT:
 
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
