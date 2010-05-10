--- modules/addressbook/evolution-module-addressbook.c.orig	2010-04-11 12:47:18.000000000 -0400
+++ modules/addressbook/evolution-module-addressbook.c	2010-04-11 12:48:06.000000000 -0400
@@ -47,3 +47,16 @@ G_MODULE_EXPORT void
 e_module_unload (GTypeModule *type_module)
 {
 }
+
+G_MODULE_EXPORT const gchar *
+g_module_check_init (GModule *module)
+{
+	/* FIXME Until addressbook is split into a module library and a
+	 *       reusable shared library, prevent the module from
+	 *       being unloaded.  Unloading the module resets all
+	 *       static variables, which screws up foo_get_type()
+	 *       functions among other things. */
+	g_module_make_resident (module);
+
+	return NULL;
+}
