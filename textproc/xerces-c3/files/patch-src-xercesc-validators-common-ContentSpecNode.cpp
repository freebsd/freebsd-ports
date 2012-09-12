--- orig/xercesc/validators/common/ContentSpecNode.cpp.orig
+++ src/xercesc/validators/common/ContentSpecNode.cpp
@@ -259,7 +259,7 @@ int ContentSpecNode::getMaxTotalRange() const {
             else {
 
                 if ((fType & 0x0f) == ContentSpecNode::Choice) {
-                    max = max * (maxFirst > maxSecond) ? maxFirst : maxSecond;
+                    max = max * ((maxFirst > maxSecond) ? maxFirst : maxSecond);
                 }
                 else {
                     max = max * (maxFirst + maxSecond);
