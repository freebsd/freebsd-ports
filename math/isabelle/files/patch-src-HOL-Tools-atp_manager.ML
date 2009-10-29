--- src/HOL/Tools/atp_manager.ML.orig	2009-10-18 10:37:58.000000000 +1100
+++ src/HOL/Tools/atp_manager.ML	2009-10-18 10:39:46.000000000 +1100
@@ -77,9 +77,9 @@
   fun ord ((a, _), (b, _)) = Time.compare (a, b);
 );
 
-val lookup_thread = AList.lookup Thread.equal;
-val delete_thread = AList.delete Thread.equal;
-val update_thread = AList.update Thread.equal;
+fun lookup_thread x = AList.lookup Thread.equal x;
+fun delete_thread x = AList.delete Thread.equal x;
+fun update_thread x = AList.update Thread.equal x;
 
 
 (* state of thread manager *)
