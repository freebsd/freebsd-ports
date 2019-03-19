--- src/drv_imap.c.orig	2019-03-19 09:37:32 UTC
+++ src/drv_imap.c
@@ -2388,7 +2388,7 @@ imap_open_box_p2( imap_store_t *ctx, imap_cmd_t *gcmd,
 	INIT_IMAP_CMD(imap_cmd_open_box_t, cmd, cmdp->callback, cmdp->callback_aux)
 	cmd->gen.param.lastuid = 1;
 	imap_exec( ctx, &cmd->gen, imap_open_box_p3,
-	           "UID FETCH *:* (UID)" );
+	           "UID FETCH * (UID)" );
 }
 
 static void
@@ -2922,7 +2922,7 @@ imap_find_new_msgs_p2( imap_store_t *ctx, imap_cmd_t *
 	cmd->uid = cmdp->uid;
 	cmd->gen.param.lastuid = 1;
 	imap_exec( ctx, &cmd->gen, imap_find_new_msgs_p3,
-	           "UID FETCH *:* (UID)" );
+	           "UID FETCH * (UID)" );
 }
 
 static void
