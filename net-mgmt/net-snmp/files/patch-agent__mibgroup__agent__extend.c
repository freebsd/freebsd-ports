--- ./agent/mibgroup/agent/extend.c.orig	2012-10-09 18:28:58.000000000 -0400
+++ ./agent/mibgroup/agent/extend.c	2012-10-24 07:46:37.000000000 -0400
@@ -34,7 +34,7 @@
     size_t              oid_len;
     long                num_entries;
     netsnmp_extend     *ehead;
-    netsnmp_handler_registration       *reg[3];
+    netsnmp_handler_registration       *reg[4];
     struct extend_registration_block_s *next;
 } extend_registration_block;
 extend_registration_block *ereg_head = NULL;
@@ -222,10 +222,13 @@
     rc = netsnmp_register_watched_scalar2( reg, winfo );
     if (rc != SNMPERR_SUCCESS)
         goto bail;
+    eptr->reg[3] = reg;
 
     return eptr;
 
 bail:
+    if (eptr->reg[3])
+        netsnmp_unregister_handler(eptr->reg[3]);
     if (eptr->reg[2])
         netsnmp_unregister_handler(eptr->reg[2]);
     if (eptr->reg[1])
@@ -267,6 +270,7 @@
         netsnmp_unregister_handler( eptr->reg[0] );
         netsnmp_unregister_handler( eptr->reg[1] );
         netsnmp_unregister_handler( eptr->reg[2] );
+        netsnmp_unregister_handler( eptr->reg[3] );
         SNMP_FREE(eptr);
     }
     ereg_head = NULL;
@@ -550,6 +554,10 @@
     }
 
     eptr      = _register_extend( oid_buf, oid_len );
+    if (!eptr) {
+        snmp_log(LOG_ERR, "Failed to register extend entry '%s' - possibly duplicate name.\n", exec_name );
+        return;
+    }
     extension = _new_extension( exec_name, flags, eptr );
     if (extension) {
         extension->command  = strdup( exec_command );
