--- src/grower.inl	2001/07/18 19:59:34	1.5
+++ src/grower.inl	2004/07/03 19:32:15	1.6
@@ -123,10 +123,10 @@
 inline CDeletingArrayGrower<T>::~CDeletingArrayGrower()
 {
   LispInt i,nr;
-  nr = NrItems();
+  nr = CDeletingArrayGrower::NrItems();
   for (i=0;i<nr;i++)
   {
-    delete Item(i);
+    delete CDeletingArrayGrower::Item(i);
   }
 }
 #endif
