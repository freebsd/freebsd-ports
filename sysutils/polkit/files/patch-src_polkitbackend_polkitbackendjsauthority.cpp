--- src/polkitbackend/polkitbackendjsauthority.cpp.orig	2022-06-25 20:41:05 UTC
+++ src/polkitbackend/polkitbackendjsauthority.cpp
@@ -75,6 +75,13 @@
 
 /* ---------------------------------------------------------------------------------------------------- */
 
+static class JsInitHelperType
+{
+public:
+	JsInitHelperType() { JS_Init(); }
+	~JsInitHelperType() { JS_ShutDown(); }
+} JsInitHelper;
+
 struct _PolkitBackendJsAuthorityPrivate
 {
   gchar **rules_dirs;
@@ -589,7 +596,6 @@ polkit_backend_js_authority_finalize (GObject *object)
   delete authority->priv->js_polkit;
 
   JS_DestroyContext (authority->priv->cx);
-  /* JS_ShutDown (); */
 
   G_OBJECT_CLASS (polkit_backend_js_authority_parent_class)->finalize (object);
 }
@@ -665,8 +671,6 @@ polkit_backend_js_authority_class_init (PolkitBackendJ
 
 
   g_type_class_add_private (klass, sizeof (PolkitBackendJsAuthorityPrivate));
-
-  JS_Init ();
 }
 
 /* ---------------------------------------------------------------------------------------------------- */
