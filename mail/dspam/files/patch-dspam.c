--- src/dspam.c.dist	Sun Apr 10 15:49:29 2005
+++ src/dspam.c	Sun Apr 10 15:52:48 2005
@@ -2733,8 +2733,9 @@
             LOG (LOG_CRIT, ERROR_MEM_ALLOC);
         }
 
-        if (CTX->result == DSR_ISSPAM)
-        {
+// FreeBSD port patch: put the user in all emails, extremely usefull for scripts
+//        if (CTX->result == DSR_ISSPAM)
+//        {
           snprintf(data, sizeof(data), "X-DSPAM-User: %s", CTX->username);
           head = _ds_create_header_field(data);
           if (head != NULL)
@@ -2746,7 +2747,7 @@
           }
           else
             LOG (LOG_CRIT, ERROR_MEM_ALLOC);
-        }
+//        } // end of FreeBSD port patch
 
         if (!strcmp(_ds_pref_val(PTX, "showFactors"), "on")) {
 
