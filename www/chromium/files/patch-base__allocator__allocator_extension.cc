--- base/allocator/allocator_extension.cc.orig	2016-01-21 17:16:30.192830309 +0100
+++ base/allocator/allocator_extension.cc	2016-01-21 17:16:49.072804621 +0100
@@ -55,7 +55,7 @@
 void SetGetNumericPropertyFunction(
     thunks::GetNumericPropertyFunction get_numeric_property_function) {
   DCHECK_EQ(thunks::GetGetNumericPropertyFunction(),
-            reinterpret_cast<thunks::GetNumericPropertyFunction>(NULL));
+            static_cast<thunks::GetNumericPropertyFunction>(NULL));
   thunks::SetGetNumericPropertyFunction(get_numeric_property_function);
 }
 
