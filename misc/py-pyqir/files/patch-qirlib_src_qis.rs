--- qirlib/src/qis.rs.orig	2023-07-30 20:03:41 UTC
+++ qirlib/src/qis.rs
@@ -1,6 +1,8 @@
 // Copyright (c) Microsoft Corporation.
 // Licensed under the MIT License.
 
+use std::os::raw::c_char;
+
 use crate::{
     builder::{build_if, try_build_if},
     types,
@@ -194,7 +196,7 @@ unsafe fn mz(module: LLVMModuleRef) -> LLVMValueRef {
 
     let function = declare_qis(module, "mz", Functor::Body, ty);
     let attr_name = "writeonly";
-    let kind_id = LLVMGetEnumAttributeKindForName(attr_name.as_ptr().cast::<i8>(), attr_name.len());
+    let kind_id = LLVMGetEnumAttributeKindForName(attr_name.as_ptr().cast::<c_char>(), attr_name.len());
     let attr = LLVMCreateEnumAttribute(context, kind_id, 0);
     let result_param_index = 2; // indices are 1 based.
     LLVMAddAttributeAtIndex(function, result_param_index, attr);
@@ -208,9 +210,9 @@ unsafe fn add_irreversible_attr(context: LLVMContextRe
     let irreversable = "irreversible";
     let irreversable_attr = LLVMCreateStringAttribute(
         context,
-        irreversable.as_ptr().cast::<i8>(),
+        irreversable.as_ptr().cast::<c_char>(),
         irreversable.len() as u32,
-        "".as_ptr().cast::<i8>(),
+        "".as_ptr().cast::<c_char>(),
         0,
     );
     LLVMAddAttributeAtIndex(function, LLVMAttributeFunctionIndex, irreversable_attr);
