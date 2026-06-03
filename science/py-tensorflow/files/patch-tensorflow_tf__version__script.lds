--- tensorflow/tf_version_script.lds.orig	2026-04-03 18:07:06 UTC
+++ tensorflow/tf_version_script.lds
@@ -18,12 +18,11 @@ tensorflow {
     *TFL*;
     *TfLite*;
     *quantization*;
-    *mlir*detail*;
-    *mlir*func*;
-    *mlir*TF*;
-    *mlir*shape*;
-    *mlir*scf*;
-    *mlir*quant*;
+    *mlir*;
+    *llvm*;
+    *LLVM*;
+    *cpuinfo*;
+    *ducc0*;
   local:
     *;
 };
