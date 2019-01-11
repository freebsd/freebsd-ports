--- v8/src/builtins/builtins-string-gen.cc.orig	2019-01-09 20:22:12.074879000 +0100
+++ v8/src/builtins/builtins-string-gen.cc	2019-01-09 21:52:28.439367000 +0100
@@ -2493,41 +2493,38 @@
   }
 }
 
-TNode<BoolT> StringBuiltinsAssembler::IsStringPrimitiveWithNoCustomIteration(
-    TNode<Object> object, TNode<Context> context) {
-  Label if_false(this, Label::kDeferred), exit(this);
-  TVARIABLE(BoolT, var_result);
+void StringBuiltinsAssembler::BranchIfStringPrimitiveWithNoCustomIteration(
+    TNode<Object> object, TNode<Context> context, Label* if_true,
+    Label* if_false) {
+  GotoIf(TaggedIsSmi(object), if_false);
+  GotoIfNot(IsString(CAST(object)), if_false);  
 
-  GotoIf(TaggedIsSmi(object), &if_false);
-  GotoIfNot(IsString(CAST(object)), &if_false);
+  // Bailout if the new array doesn't fit in new space.
+  const TNode<IntPtrT> length = LoadStringLengthAsWord(CAST(object));
+  // Since we don't have allocation site, base size does not include
+  // AllocationMemento::kSize.
+  GotoIfFixedArraySizeDoesntFitInNewSpace(
+      length, if_false, JSArray::kSize + FixedArray::kHeaderSize,
+      INTPTR_PARAMETERS);
 
   // Check that the String iterator hasn't been modified in a way that would
   // affect iteration.
   Node* protector_cell = LoadRoot(RootIndex::kStringIteratorProtector);
   DCHECK(isolate()->heap()->string_iterator_protector()->IsPropertyCell());
-  var_result =
-      WordEqual(LoadObjectField(protector_cell, PropertyCell::kValueOffset),
-                SmiConstant(Isolate::kProtectorValid));
-  Goto(&exit);
-
-  BIND(&if_false);
-  {
-    var_result = Int32FalseConstant();
-    Goto(&exit);
-  }
-
-  BIND(&exit);
-  return var_result.value();
+  Branch(WordEqual(LoadObjectField(protector_cell, PropertyCell::kValueOffset),
+                   SmiConstant(Isolate::kProtectorValid)),
+         if_true, if_false);
 }
 
+// This function assumes StringPrimitiveWithNoCustomIteration is true.
 TNode<JSArray> StringBuiltinsAssembler::StringToList(TNode<Context> context,
                                                      TNode<String> string) {
-  CSA_ASSERT(this, IsStringPrimitiveWithNoCustomIteration(string, context));
   const ElementsKind kind = PACKED_ELEMENTS;
   const TNode<IntPtrT> length = LoadStringLengthAsWord(string);
 
   Node* const array_map =
       LoadJSArrayElementsMap(kind, LoadNativeContext(context));
+  // Allocate the array to new space, assuming that the new array will fit in.
   Node* const array = AllocateJSArray(kind, array_map, length, SmiTag(length));
   Node* const elements = LoadElements(array);
 
