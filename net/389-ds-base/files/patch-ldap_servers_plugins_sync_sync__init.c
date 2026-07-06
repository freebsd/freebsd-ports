--- ldap/servers/plugins/sync/sync_init.c.orig	2026-06-28 10:07:36 UTC
+++ ldap/servers/plugins/sync/sync_init.c
@@ -310,7 +310,7 @@ sync_persist_get_operation_extension(Slapi_PBlock *pb)
     ident = slapi_get_object_extension(sync_persist_extension_type, op,
                                        sync_persist_extension_handle);
     slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "sync_persist_get_operation_extension operation (op=0x%lx) -> %d\n",
-                    (ulong) op, ident ? ident->idx_pl : -1);
+                    (unsigned long) op, ident ? ident->idx_pl : -1);
     return (op_ext_ident_t *) ident;
 
 }
@@ -322,7 +322,7 @@ sync_persist_set_operation_extension(Slapi_PBlock *pb,
 
     slapi_pblock_get(pb, SLAPI_OPERATION, &op);
     slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "sync_persist_set_operation_extension operation (op=0x%lx) -> %d\n",
-                    (ulong) op, op_ident ? op_ident->idx_pl : -1);
+                    (unsigned long) op, op_ident ? op_ident->idx_pl : -1);
     slapi_set_object_extension(sync_persist_extension_type, op,
                                sync_persist_extension_handle, (void *)op_ident);
 }
