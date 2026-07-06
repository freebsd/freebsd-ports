--- ldap/servers/plugins/sync/sync_persist.c.orig	2026-06-28 10:01:47 UTC
+++ ldap/servers/plugins/sync/sync_persist.c
@@ -153,7 +153,7 @@ sync_update_persist_betxn_pre_op(Slapi_PBlock *pb)
         PR_ASSERT(current_op->flags == OPERATION_PL_PENDING);
         slapi_log_err(SLAPI_LOG_WARNING, SYNC_PLUGIN_SUBSYSTEM, "sync_update_persist_betxn_pre_op - DB retried operation targets "
                       "\"%s\" (op=0x%lx idx_pl=%d) => op not changed in PL\n",
-                      slapi_sdn_get_dn(sdn), (ulong) op, idx_pl);
+                      slapi_sdn_get_dn(sdn), (unsigned long) op, idx_pl);
         return 0;
     }
 
@@ -177,7 +177,7 @@ sync_update_persist_betxn_pre_op(Slapi_PBlock *pb)
                    */
         slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "sync_update_persist_betxn_pre_op - nested operation targets "
                       "\"%s\" (op=0x%lx idx_pl=%d)\n",
-                      slapi_sdn_get_dn(sdn), (ulong) new_op->op, idx_pl);
+                      slapi_sdn_get_dn(sdn), (unsigned long) new_op->op, idx_pl);
     } else {
         /* The current operation is the first/primary one in the txn
          * registers it directly in the thread private data (head)
@@ -186,7 +186,7 @@ sync_update_persist_betxn_pre_op(Slapi_PBlock *pb)
         idx_pl = 0; /* as primary operation, its index in the pending list is 0 */
         slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "sync_update_persist_betxn_pre_op - primary operation targets "
                       "\"%s\" (0x%lx)\n",
-                      slapi_sdn_get_dn(sdn), (ulong) new_op->op);
+                      slapi_sdn_get_dn(sdn), (unsigned long) new_op->op);
     }
 
     /* records, in the operation extension AND in the pending list, the identifier (index) of
@@ -225,7 +225,7 @@ ignore_op_pl(Slapi_PBlock *pb)
          */
         slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM,
               "ignore_op_pl - Operation without primary op set (0x%lx)\n",
-              (ulong) op);
+              (unsigned long) op);
         return;
     }
     ident = sync_persist_get_operation_extension(pb);
@@ -243,14 +243,14 @@ ignore_op_pl(Slapi_PBlock *pb)
                  */
                 PR_ASSERT(curr_op->flags == OPERATION_PL_PENDING);
                 slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "ignore_op_pl operation (op=0x%lx, idx_pl=%d) from the pending list\n",
-                        (ulong) op, ident->idx_pl);
+                        (unsigned long) op, ident->idx_pl);
                 curr_op->flags = OPERATION_PL_IGNORED;
                 return;
             }
         }
     }
     slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "ignore_op_pl failing operation (op=0x%lx, idx_pl=%d) was not in the pending list\n",
-                    (ulong) op, ident ? ident->idx_pl : -1);
+                    (unsigned long) op, ident ? ident->idx_pl : -1);
 }
 
 /* This is a generic function that is called by betxn_post of this plugin.
@@ -291,14 +291,14 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
         if (0 != rc) {
             /* The internal operation did not succeed */
             slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "internal operation Failed (0x%lx) rc=%d\n",
-                       (ulong) pb_op, rc);
+                       (unsigned long) pb_op, rc);
         }
     } else {
         slapi_pblock_get(pb, SLAPI_PLUGIN_OPRETURN, &rc);
         if (0 != rc) {
             /* The operation did not succeed */
             slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "direct operation Failed (0x%lx) rc=%d\n",
-                       (ulong) pb_op, rc);
+                       (unsigned long) pb_op, rc);
         }
     }
 
@@ -312,7 +312,7 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
          */
         slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM,
                       "sync_update_persist_op - Operation without primary op set (0x%lx)\n",
-                      (ulong) pb_op);
+                      (unsigned long) pb_op);
         return;
     }
     ident = sync_persist_get_operation_extension(pb);
@@ -322,7 +322,7 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
          * As a NOOP betxn plugins are not called and operation ext is not created
          */
         slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "Skip noop operation (0x%lx)\n",
-                       (ulong) pb_op);
+                       (unsigned long) pb_op);
         return;
     }
     assert(ident);
@@ -351,7 +351,7 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
     }
     if (!curr_op) {
         slapi_log_err(SLAPI_LOG_ERR, SYNC_PLUGIN_SUBSYSTEM, "%s - operation (op=0x%lx, idx_pl=%d) not found on the pendling list\n",
-                      label, (ulong) pb_op, ident->idx_pl);
+                      label, (unsigned long) pb_op, ident->idx_pl);
         PR_ASSERT(curr_op);
     }
 
@@ -391,7 +391,7 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
 
             }
             slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "dump pending list(0x%lx) %s %s\n",
-                    (ulong) curr_op->op, entry_str, flags_str);
+                    (unsigned long) curr_op->op, entry_str, flags_str);
         }
     }
 
@@ -402,7 +402,7 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
         }
     }
     if (curr_op) {
-        slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "%s - It remains a pending operation (0x%lx)\n", label, (ulong) curr_op->op);
+        slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "%s - It remains a pending operation (0x%lx)\n", label, (unsigned long) curr_op->op);
     } else {
         OPERATION_PL_CTX_T *next = NULL;
         PRBool enqueue_it = PR_TRUE;
@@ -427,7 +427,7 @@ sync_update_persist_op(Slapi_PBlock *pb, Slapi_Entry *
                 entry = "unknown";
             }
             slapi_log_err(SLAPI_LOG_PLUGIN, SYNC_PLUGIN_SUBSYSTEM, "Do %s enqueue (0x%lx) %s\n",
-                    enqueue_it ? "" : "not", (ulong) curr_op->op, entry);
+                    enqueue_it ? "" : "not", (unsigned long) curr_op->op, entry);
             if (enqueue_it) {
                 sync_queue_change(curr_op);
             }
