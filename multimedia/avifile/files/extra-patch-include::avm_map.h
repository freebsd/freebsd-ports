--- include/avm_map.h.orig	Fri Aug  6 12:35:41 2004
+++ include/avm_map.h	Fri Aug  6 12:37:10 2004
@@ -198,7 +198,8 @@
 {
     // cast to the needed type - used to prevent internal compiler error
     // for old egcc
-    avm_map<Key, Value, Compare, Equal>::_Tnode* node = (avm_map<Key, Value, Compare, Equal>::_Tnode*) n;
+    //avm_map<Key, Value, Compare, Equal>::_Tnode* node = (avm_map<Key, Value, Compare, Equal>::_Tnode*) n;
+    _Tnode* node = (_Tnode*) n;
 
     if(node->entry)
     {
