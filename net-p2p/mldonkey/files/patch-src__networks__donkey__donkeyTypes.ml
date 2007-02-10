--- ./src/networks/donkey/donkeyTypes.ml.orig	Sun Nov 26 14:36:06 2006
+++ ./src/networks/donkey/donkeyTypes.ml	Sat Feb 10 07:00:40 2007
@@ -602,6 +602,8 @@
     mutable up_pos : int64;
     mutable up_end_chunk : int64;
     mutable up_chunks : (int64 * int64) list;
+    (* zones sent but not yet received by other peer, oldest first *)
+    mutable up_flying_chunks : (int64 * int64) list; 
     mutable up_waiting : bool;
   }
 
