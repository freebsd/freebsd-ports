--- src/csv.mli.orig	2010-06-14 11:17:06 UTC
+++ src/csv.mli
@@ -37,7 +37,7 @@ type t = string list list
 (** The most basic input object for best interoperability. *)
 class type in_obj_channel =
 object
-  method input : string -> int -> int -> int
+  method input : bytes -> int -> int -> int
     (** [input buf ofs len] reads up to [len] octets from the channel
         and puts them in the substring [buf.[ofs .. ofs+len-1]].
         Returns the number of octets actually read (and stored).  When
@@ -52,7 +52,7 @@ end
 (** The most basic output object for best interoperability. *)
 class type out_obj_channel =
 object
-  method output : string -> int -> int -> int
+  method output : bytes -> int -> int -> int
     (** [output s ofs len] writes up to [len] bytes of the substring
         [s.[ofs .. ofs+len-1]].  Return the number of bytes actually
         written.  When the channel is non-blocking, and there are
