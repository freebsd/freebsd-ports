diff --git a/sysutils/fluent-bit/files/patch-plugins_in__tail_tail__fs__inotify.c b/sysutils/fluent-bit/files/patch-plugins_in__tail_tail__fs__inotify.c
new file mode 100644
index 00000000000..1b638908f85
--- /dev/null
+++ b/sysutils/fluent-bit/files/patch-plugins_in__tail_tail__fs__inotify.c
@@ -0,0 +1,11 @@
+--- plugins/in_tail/tail_fs_inotify.c.orig	2026-01-21 11:26:30 UTC
++++ plugins/in_tail/tail_fs_inotify.c
+@@ -107,7 +107,7 @@ static int tail_fs_add(struct flb_tail_file *file, int
+      * lines from the file and once we reach EOF (and a watch_fd exists),
+      * we update the flags to receive notifications.
+      */
+-    flags = IN_ATTRIB | IN_IGNORED | IN_MODIFY | IN_Q_OVERFLOW;
++    flags = IN_ATTRIB | IN_MODIFY;
+ 
+     if (check_rotated == FLB_TRUE) {
+         flags |= IN_MOVE_SELF;
