Index: panels/printers/pp-host.c
--- panels/printers/pp-host.c.orig
+++ panels/printers/pp-host.c
@@ -256,7 +256,7 @@ _pp_host_get_snmp_devices_thread (GTask        *task,
   devices = g_ptr_array_new_with_free_func (g_object_unref);
 
   argv = g_new0 (gchar *, 3);
-  argv[0] = g_strdup ("/usr/lib/cups/backend/snmp");
+  argv[0] = g_strdup ("${LOCALBASE}/libexec/cups/backend/snmp");
   argv[1] = g_strdup (priv->hostname);
 
   /* Use SNMP to get printer's informations */
