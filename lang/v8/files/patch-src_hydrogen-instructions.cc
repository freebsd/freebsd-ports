--- src/hydrogen-instructions.cc.orig	2011-08-31 17:03:56.000000000 +0800
+++ src/hydrogen-instructions.cc	2011-09-23 20:39:25.000000000 +0800
@@ -1203,10 +1203,10 @@ void HBinaryOperation::PrintDataTo(Strin
 Range* HBitAnd::InferRange() {
   int32_t left_mask = (left()->range() != NULL)
       ? left()->range()->Mask()
-      : 0xffffffff;
+      : (int32_t) 0xffffffff;
   int32_t right_mask = (right()->range() != NULL)
       ? right()->range()->Mask()
-      : 0xffffffff;
+      : (int32_t) 0xffffffff;
   int32_t result_mask = left_mask & right_mask;
   return (result_mask >= 0)
       ? new Range(0, result_mask)
@@ -1217,10 +1217,10 @@ Range* HBitAnd::InferRange() {
 Range* HBitOr::InferRange() {
   int32_t left_mask = (left()->range() != NULL)
       ? left()->range()->Mask()
-      : 0xffffffff;
+      : (int32_t) 0xffffffff;
   int32_t right_mask = (right()->range() != NULL)
       ? right()->range()->Mask()
-      : 0xffffffff;
+      : (int32_t) 0xffffffff;
   int32_t result_mask = left_mask | right_mask;
   return (result_mask >= 0)
       ? new Range(0, result_mask)
