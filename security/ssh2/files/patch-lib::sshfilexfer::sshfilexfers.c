--- lib/sshfilexfer/sshfilexfers.c.orig	2003-12-03 15:17:22.000000000 +0200
+++ lib/sshfilexfer/sshfilexfers.c	2006-02-22 10:44:25.000000000 +0200
@@ -5,7 +5,7 @@
   Authors: Tatu Ylonen   <ylo@ssh.com>
            Sami Lehtinen <sjl@ssh.com>
           
-  Copyright (c) 1998-2001 SSH Communications Security Corp, Finland
+  Copyright (c) 1998-2001, 2006 SSH Communications Security Corp, Finland
                           All rights reserved
 
   Generic file transfer module, server side.
@@ -115,7 +115,8 @@
   if (server->log_facility >= 0)                                             \
     {                                                                        \
       char *msg = ssh_debug_format varcall;                                  \
-      ssh_log_event(det_fac(category, server->log_facility), severity, msg); \
+      ssh_log_event(det_fac(category, server->log_facility), severity,  \
+                    "%s", msg);                                         \
       ssh_xfree(msg);                                                        \
     }                                                                        \
 } while (0)
