--- src/Util/utilTime.sml.orig	Mon May 28 15:08:45 2007
+++ src/Util/utilTime.sml	Mon May 28 15:09:58 2007
@@ -12,8 +12,8 @@
 (*--------------------------------------------------------------------------*)
 signature UtilTime =
    sig
-      val time  : ('a -> 'b) -> 'a -> 'b * {usr:Time.time, sys:Time.time, gc:Time.time} 
-      val timeN : int -> ('a -> 'b) -> 'a -> 'b * {usr:Time.time, sys:Time.time, gc:Time.time} 
+      val time  : ('a -> 'b) -> 'a -> 'b * {usr:Time.time, sys:Time.time} 
+      val timeN : int -> ('a -> 'b) -> 'a -> 'b * {usr:Time.time, sys:Time.time} 
    end
 
 structure UtilTime : UtilTime =
