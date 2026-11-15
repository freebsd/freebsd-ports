--- common/core_commands6.cc.orig	2026-11-15 03:37:32 UTC
+++ common/core_commands6.cc
@@ -1013,8 +1013,8 @@ int docmd_stoflag(arg_struct *arg) {
         p <<= 1;
     }
 
-    char new_g = !flags.f.rad && flags.f.grad;
-    char new_rad = flags.f.rad || flags.f.grad;
+    signed char new_g = !flags.f.rad && flags.f.grad;
+    signed char new_rad = flags.f.rad || flags.f.grad;
     if (new_g == old_g)
         new_g = -1;
     if (new_rad == old_rad)
