--- src/exim.c.orig	Wed Aug 15 13:09:09 2001
+++ src/exim.c	Fri Nov  2 12:22:38 2001
@@ -2197,7 +2197,8 @@
 
 if (!admin_user)
   {
-  if (deliver_give_up || daemon_listen || count_queue ||
+  if (deliver_give_up || daemon_listen ||
+     (count_queue && queue_list_requires_admin) ||
      (list_queue && queue_list_requires_admin) ||
      (queue_interval >= 0 && prod_requires_admin))
     {
