--- v8/src/builtins/builtins-string-gen.h.orig	2019-01-09 20:22:23.363855000 +0100
+++ v8/src/builtins/builtins-string-gen.h	2019-01-09 20:25:02.361877000 +0100
@@ -23,8 +23,10 @@
                         Node* rhs, Node* rhs_instance_type,
                         TNode<IntPtrT> length, Label* if_equal,
                         Label* if_not_equal, Label* if_indirect);
-  TNode<BoolT> IsStringPrimitiveWithNoCustomIteration(TNode<Object> object,
-                                                      TNode<Context> context);
+  void BranchIfStringPrimitiveWithNoCustomIteration(TNode<Object> object,
+                                                    TNode<Context> context,
+                                                    Label* if_true,
+                                                    Label* if_false);
 
  protected:
   TNode<JSArray> StringToList(TNode<Context> context, TNode<String> string);
