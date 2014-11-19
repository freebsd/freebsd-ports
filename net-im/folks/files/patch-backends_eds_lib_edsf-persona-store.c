--- backends/eds/lib/edsf-persona-store.c.orig	2014-06-22 23:29:00.567592303 +0000
+++ backends/eds/lib/edsf-persona-store.c	2014-06-22 23:30:17.689586171 +0000
@@ -10968,6 +10968,24 @@
 	_edsf_persona_store_notify_if_default (self);
 }
 
+struct _FolksPersonaStorePrivate {
+        gchar* _display_name;
+        gchar* _id;
+        gboolean _is_writeable;
+        FolksPersonaStoreTrust _trust_level;
+        gboolean _is_primary_store;
+        gboolean _is_user_set_default;
+};
+
+void folks_persona_store_set_is_user_set_default (FolksPersonaStore* self, gboolean value);
+
+void folks_persona_store_set_is_user_set_default (FolksPersonaStore* self, gboolean value) {
+        gboolean _tmp0_ = FALSE;
+        g_return_if_fail (self != NULL);
+        _tmp0_ = value;
+        self->priv->_is_user_set_default = _tmp0_;
+        g_object_notify ((GObject *) self, "is-user-set-default");
+}
 
 static void _edsf_persona_store_notify_if_default (EdsfPersonaStore* self) {
 	gboolean is_default = FALSE;
