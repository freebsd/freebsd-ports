--- number.ml	Thu Oct 21 04:56:03 2004
+++ number.ml	Thu Nov 25 00:25:35 2004
@@ -18,7 +18,7 @@
 (** Basic operations and definitions for multi-precistion integers. *)

 (* Change to Dlong for non x86 platforms *)
-module Nx = Numerix.Slong
+module Nx = Numerix.Clong

 let two = Nx.of_int 2
 let one = Nx.of_int 1
