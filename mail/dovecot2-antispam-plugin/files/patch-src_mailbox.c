diff -r 43880985e3dd -r 5e8351bcfb29 src/mailbox.c
--- src/mailbox.c	Wed Dec 22 22:34:22 2010 +0200
+++ src/mailbox.c	Sun Feb 26 21:34:05 2012 +0200
@@ -135,7 +135,7 @@
     struct mailbox_transaction_context *t = ctx->transaction;
     struct antispam_mailbox *asmb = STORAGE_CONTEXT(t->box);
 
-    if (ctx->copying == 0)
+    if (ctx->copying_via_save == 0)
     {
 	struct antispam_user *asu = USER_CONTEXT(t->box->storage->user);
 
@@ -171,7 +171,7 @@
 
     // if we are copying then copy() code will do everything needed
     int ret = asmb->module_ctx.super.save_finish(ctx);
-    if (ctx->copying != 0 || ret != 0)
+    if (ctx->copying_via_save != 0 || ret != 0)
 	return ret;
 
     // since there is no source mailbox, let's assume


