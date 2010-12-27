#
#  Fix regression in 2.3.6 which broke process controls when using vhost-
#  specific configuration.
#
Index: modules/fcgid/fcgid_spawn_ctl.c
===================================================================
--- modules/fcgid/fcgid_spawn_ctl.c	(revision 1037726)
+++ modules/fcgid/fcgid_spawn_ctl.c	(revision 1037727)
@@ -178,7 +178,7 @@
         if (current_node->inode == command->inode
             && current_node->deviceid == command->deviceid
             && !strcmp(current_node->cmdline, command->cmdline)
-            && current_node->vhost_id == sconf->vhost_id
+            && current_node->vhost_id == command->vhost_id
             && current_node->uid == command->uid
             && current_node->gid == command->gid)
             break;
