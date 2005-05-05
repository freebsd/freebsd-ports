--- src/dspam.c.dist	Wed Apr 27 14:45:51 2005
+++ src/dspam.c	Wed Apr 27 14:47:50 2005
@@ -2966,8 +2966,9 @@
             LOG (LOG_CRIT, ERR_MEM_ALLOC);
         }
 
-        if (CTX->result == DSR_ISSPAM)
-        {
+// FreeBSD port patch: put the user in all emails, extremely usefull for scripts
+//        if (CTX->result == DSR_ISSPAM)
+//        {
           snprintf(data, sizeof(data), "X-DSPAM-User: %s", CTX->username);
           head = _ds_create_header_field(data);
           if (head != NULL)
@@ -2979,7 +2980,7 @@
           }
           else
             LOG (LOG_CRIT, ERR_MEM_ALLOC);
-        }
+//        } // // end of FreeBSD port patch
 
         if (!strcmp(_ds_pref_val(ATX->PTX, "showFactors"), "on")) {
 
