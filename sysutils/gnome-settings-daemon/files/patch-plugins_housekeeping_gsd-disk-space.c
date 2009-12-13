--- plugins/housekeeping/gsd-disk-space.c.orig	2009-12-11 12:14:35.000000000 -0500
+++ plugins/housekeeping/gsd-disk-space.c	2009-12-11 12:14:56.000000000 -0500
@@ -315,6 +315,7 @@
                 "procfs",
                 "ptyfs",
                 "selinuxfs",
+                "linsysfs",
                 "sysfs",
                 "tmpfs",
                 "usbfs",
