#
# fix connection drop handling in a data-acl
#  <http://www.exim.org/pipermail/exim-users/Week-of-Mon-20040510/071573.html>
#
--- src/daemon.c.orig	Fri May 14 19:25:24 2004
+++ src/daemon.c	Fri May 14 19:26:52 2004
@@ -452,7 +452,11 @@
       {
       BOOL ok = receive_msg(FALSE);
       search_tidyup();                    /* Close cached databases */
-      if (!ok) _exit(EXIT_SUCCESS);       /* Connection was dropped */
+      if (!ok)
+        {
+        mac_smtp_fflush();
+        _exit(EXIT_SUCCESS);              /* Connection was dropped */
+        }
       if (message_id[0] == 0) continue;   /* No message was accepted */
       }
     else
