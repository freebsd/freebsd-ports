--- ./agent/helpers/old_api.c.orig	2011-12-07 17:43:45.000000000 -0500
+++ ./agent/helpers/old_api.c	2011-12-07 17:44:06.000000000 -0500
@@ -127,7 +127,7 @@
          */
         if (netsnmp_register_handler(reginfo) != MIB_REGISTERED_OK) {
             /** netsnmp_handler_registration_free(reginfo); already freed */
-            SNMP_FREE(vp);
+            /* SNMP_FREE(vp); already freed */
         }
     }
     return SNMPERR_SUCCESS;
