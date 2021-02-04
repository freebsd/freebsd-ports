--- modules/system-source/system-source.c.orig 2021-01-13 10:46:26.320565000 +0100
+++ modules/system-source/system-source.c 2021-01-13 10:52:26.747801000 +0100
@@ -164,7 +164,7 @@
       strncmp(release, "9.0", 3) == 0)
     system_sysblock_add_file(sysblock, "/dev/klog", 1, "kernel", "no-parse", NULL, FALSE);
   else
-    system_sysblock_add_file(sysblock, "/dev/klog", 0, "kernel", "no-parse", NULL, FALSE);
+    system_sysblock_add_file(sysblock, "/dev/klog", 0, "kernel", NULL, NULL, FALSE);
 }

 static gboolean
