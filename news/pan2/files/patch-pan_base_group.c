--- pan/base/group.c.orig	Mon Apr 21 20:52:11 2003
+++ pan/base/group.c	Mon Apr 21 20:52:32 2003
@@ -206,7 +206,7 @@
 groups_set_subscribed (Group ** groups, gint qty, gboolean subscribed)
 {
 	Group ** changed;
-	Server * server;
+	Server * server = NULL;
 	const ServerGroupsType type = SERVER_GROUPS_SUBSCRIBED|SERVER_GROUPS_UNSUBSCRIBED;
 	int changed_qty = 0;
 	int i;
