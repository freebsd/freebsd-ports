--- src/3rdparty/chromium/base/pickle.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/pickle.cc
@@ -82,7 +82,12 @@ inline const char* PickleIterator::GetReadPointerAndAd
 }
 
 bool PickleIterator::ReadBool(bool* result) {
-  return ReadBuiltinType(result);
+  int int_result;
+  if (ReadBuiltinType(&int_result)) {
+    *result = static_cast<bool>(int_result);
+    return true;
+  } else
+    return false;
 }
 
 bool PickleIterator::ReadInt(int* result) {
