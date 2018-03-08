--- src/runit.c.orig	2018-03-06 14:39:19 UTC
+++ src/runit.c
@@ -309,10 +309,10 @@ int main (int argc, const char * const *argv, char * c
     reboot_system(RB_AUTOBOOT);
   }
   else {
-#ifdef RB_POWER_OFF
+#ifdef RB_POWEROFF
     strerr_warn2(INFO, "power off...", 0);
     sync();
-    reboot_system(RB_POWER_OFF);
+    reboot_system(RB_POWEROFF);
     sleep(2);
 #endif
 #ifdef RB_HALT_SYSTEM
