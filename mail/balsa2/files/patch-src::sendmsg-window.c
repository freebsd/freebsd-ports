ADDED FILE: files/patch-src::sendmsg-window.c

--- src/sendmsg-window.c.orig	Thu Feb  7 10:04:41 2002
+++ src/sendmsg-window.c	Thu Feb  7 10:04:50 2002
@@ -785,7 +785,7 @@
         return; 
     } 
     if (pid == 0) {
-        setpgrp();
+        setpgrp(0, 0);
         
         command = g_strdup_printf(balsa_app.extern_editor_command, filename); 
         cmdline = g_strsplit(command, " ", 1024); 
