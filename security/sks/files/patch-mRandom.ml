--- mRandom.ml.orig	Thu Oct 21 06:56:03 2004
+++ mRandom.ml	Tue Nov  9 16:34:27 2004
@@ -92,7 +92,7 @@ struct
 
   (* Low-entropy system-dependent initialisation. *)
 
-  external random_seed: unit -> int = "sys_random_seed"
+  external random_seed: unit -> int = "caml_sys_random_seed"
 
   let self_init () = init (random_seed())
 
