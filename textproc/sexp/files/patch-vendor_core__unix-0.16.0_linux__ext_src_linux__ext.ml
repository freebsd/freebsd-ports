--- vendor/core_unix-0.16.0/linux_ext/src/linux_ext.ml.orig	2023-04-25 13:12:26 UTC
+++ vendor/core_unix-0.16.0/linux_ext/src/linux_ext.ml
@@ -460,7 +460,7 @@ module Clock = Null.Clock
 module Clock = Null.Clock
 
 [%%endif]
-[%%ifdef JSC_TIMERFD]
+[%%if defined(JSC_LINUX_EXT) && defined(JSC_TIMERFD)]
 
 module Timerfd = struct
   module Clock : sig
