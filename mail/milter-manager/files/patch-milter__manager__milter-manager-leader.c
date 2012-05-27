--- ./milter/manager/milter-manager-leader.c.orig	2012-02-27 11:32:27.116034000 +0900
+++ ./milter/manager/milter-manager-leader.c	2012-05-25 07:45:44.000000000 +0900
@@ -149,7 +149,7 @@
     priv->configuration = NULL;
     priv->client_context = NULL;
     priv->children = NULL;
-    priv->state = MILTER_SERVER_CONTEXT_STATE_START;
+    priv->state = MILTER_MANAGER_LEADER_STATE_START;
     priv->sent_end_of_message = FALSE;
     priv->launcher_read_channel = NULL;
     priv->launcher_write_channel = NULL;