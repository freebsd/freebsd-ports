--- src/mwgaim.c.orig	Thu Jun 24 20:55:29 2004
+++ src/mwgaim.c	Thu Jun 24 20:56:30 2004
@@ -723,11 +723,14 @@
 
 
 static char *mw_list_status_text(GaimBuddy *b) {
+  struct mw_plugin_data *pd;
+  struct mwIdBlock i = { b->name, NULL };
+  const char *t;
+
   g_return_val_if_fail(b, NULL);
 
-  struct mw_plugin_data *pd = PLUGIN_DATA(b->account->gc);
-  struct mwIdBlock i = { b->name, NULL };
-  const char *t = mwServiceAware_getText(pd->srvc_aware, &i);
+  pd = PLUGIN_DATA(b->account->gc);
+  t = mwServiceAware_getText(pd->srvc_aware, &i);
   return t? g_strdup(t): NULL;
 }
 
