--- src/polkitbackend/polkitbackendjsauthority.cpp.orig	2019-04-02 12:54:12 UTC
+++ src/polkitbackend/polkitbackendjsauthority.cpp
@@ -567,6 +567,8 @@ polkit_backend_js_authority_finalize (GObject *object)
   g_strfreev (authority->priv->rules_dirs);
 
   delete authority->priv->ac;
+  delete authority->priv->js_global;
+  delete authority->priv->js_polkit;
 
   JS_DestroyContext (authority->priv->cx);
   /* JS_ShutDown (); */
