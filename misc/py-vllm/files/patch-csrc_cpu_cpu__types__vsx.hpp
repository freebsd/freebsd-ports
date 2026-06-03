--- csrc/cpu/cpu_types_vsx.hpp.orig	2026-05-15 01:00:58.314737000 +0200
+++ csrc/cpu/cpu_types_vsx.hpp	2026-05-15 01:00:58.314987000 +0200
@@ -64,7 +64,7 @@
 } f32x4x4_t;
 
 typedef struct i32x4x4_t {
-  __vector int32_t val[4];
+  __vector int val[4];
 } i32x4x4_t;
 
 struct FP32Vec8;
@@ -76,7 +76,7 @@
   __vector signed short reg;
 
   explicit BF16Vec8(const void* ptr)
-      : reg((__vector signed short)vec_xl(0, (__vector signed short*)ptr)) {}
+      : reg((__vector signed short)vec_xl(0, (signed short*)ptr)) {}
 
   explicit BF16Vec8(const FP32Vec8&);
 
@@ -294,20 +294,20 @@
   i32x4x4_t reg;
 
   explicit INT32Vec16(const void* data_ptr) {
-    reg.val[0] = vec_xl(0, reinterpret_cast<const __vector int32_t*>(data_ptr));
+    reg.val[0] = vec_xl(0, reinterpret_cast<const int32_t*>(data_ptr));
     reg.val[1] =
-        vec_xl(16, reinterpret_cast<const __vector int32_t*>(data_ptr));
+        vec_xl(16, reinterpret_cast<const int32_t*>(data_ptr));
     reg.val[2] =
-        vec_xl(32, reinterpret_cast<const __vector int32_t*>(data_ptr));
+        vec_xl(32, reinterpret_cast<const int32_t*>(data_ptr));
     reg.val[3] =
-        vec_xl(48, reinterpret_cast<const __vector int32_t*>(data_ptr));
+        vec_xl(48, reinterpret_cast<const int32_t*>(data_ptr));
   }
 
   void save(int32_t* ptr) const {
-    vec_xst(reg.val[0], 0, reinterpret_cast<__vector int32_t*>(ptr));
-    vec_xst(reg.val[1], 16, reinterpret_cast<__vector int32_t*>(ptr));
-    vec_xst(reg.val[2], 32, reinterpret_cast<__vector int32_t*>(ptr));
-    vec_xst(reg.val[3], 48, reinterpret_cast<__vector int32_t*>(ptr));
+    vec_xst(reg.val[0], 0, reinterpret_cast<int32_t*>(ptr));
+    vec_xst(reg.val[1], 16, reinterpret_cast<int32_t*>(ptr));
+    vec_xst(reg.val[2], 32, reinterpret_cast<int32_t*>(ptr));
+    vec_xst(reg.val[3], 48, reinterpret_cast<int32_t*>(ptr));
   }
 
   void save(int32_t* ptr, const int elem_num) const {
