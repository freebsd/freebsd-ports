--- lib/command.c.orig	2018-02-04 17:34:34 UTC
+++ lib/command.c
@@ -3127,15 +3127,15 @@ DEFUN (config_write_file, 
   
   if ((dupfd = dup (file_vty->wfd)) < 0)
     {
-      vty_out (vty, "Couldn't dup fd (for fdatasync) for %s, %s (%d).%s", 
+      vty_out (vty, "Couldn't dup fd (for fsync) for %s, %s (%d).%s", 
                config_file, safe_strerror(errno), errno, VTY_NEWLINE);
     }
 
   vty_close (file_vty);
   
-  if (fdatasync (dupfd) < 0)
+  if (fsync (dupfd) < 0)
     {
-      vty_out (vty, "Couldn't fdatasync %s, %s (%d)!%s",
+      vty_out (vty, "Couldn't fsync %s, %s (%d)!%s",
                config_file, safe_strerror(errno), errno, VTY_NEWLINE);
     }
 
