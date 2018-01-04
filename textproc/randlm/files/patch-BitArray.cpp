--- src/LDHT/BitArray.cpp.orig	2017-03-07 01:14:52 UTC
+++ src/LDHT/BitArray.cpp
@@ -115,7 +115,7 @@ uint64_t BitArray::getLength() {
 }
 
 bool BitArray::validArrayIndex(uint64_t index) {
-    if (index >= 0 && index <= getLength())
+    if (index >= 1 && index <= getLength())
         return true;
     else
         return false;
