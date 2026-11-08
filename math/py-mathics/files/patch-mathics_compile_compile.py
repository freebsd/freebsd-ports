Description: Do not call llvmlite.binding.initialize(), which raises since
  llvmlite 0.45.
Issue ID: none
Changeset: https://github.com/Mathics3/mathics-core/commit/647fff8a
TODO: Drop when updating to Mathics 10.0 or later.

--- mathics/compile/compile.py.orig	2023-03-26 05:39:05 UTC
+++ mathics/compile/compile.py
@@ -6,7 +6,6 @@ from mathics.compile.ir import IRGenerat
 from mathics.compile.utils import llvm_to_ctype
 
 # setup llvm for code generation
-llvm.initialize()
 llvm.initialize_native_target()
 llvm.initialize_native_asmprinter()  # yes, even this one
 
