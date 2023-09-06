--- src/runit.h.orig	2023-06-06 12:35:21 UTC
+++ src/runit.h
@@ -1,4 +1,5 @@
-#define RUNIT "/sbin/runit"
-#define STOPIT "/etc/runit/stopit"
-#define REBOOT "/etc/runit/reboot"
-#define CTRLALTDEL "/etc/runit/ctrlaltdel"
+#define PREFIX "%%PREFIX%%"
+#define RUNIT PREFIX "/sbin/runit"
+#define STOPIT PREFIX "/etc/runit/stopit"
+#define REBOOT PREFIX "/etc/runit/reboot"
+#define CTRLALTDEL PREFIX "/etc/runit/ctrlaltdel"
