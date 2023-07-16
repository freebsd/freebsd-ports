--- init/reboot.h.orig	2023-07-16 21:31:29 UTC
+++ init/reboot.h
@@ -12,6 +12,9 @@
 #  define RB_DISABLE_CAD  0
 #  define RB_POWER_OFF    0x4321fedc
 #  define RB_AUTOBOOT     0x01234567
+# elif defined(__FreeBSD__)
+#  define RB_HALT_SYSTEM RB_HALT
+#  define RB_POWER_OFF RB_POWEROFF
 # elif defined(RB_HALT)
 #  define RB_HALT_SYSTEM  RB_HALT
 # endif
