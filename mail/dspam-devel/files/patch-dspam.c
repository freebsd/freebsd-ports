--- src/dspam.c.dist	Sun Feb 20 22:42:47 2005
+++ src/dspam.c	Sun Feb 20 22:46:22 2005
@@ -2543,8 +2543,9 @@
           LOG (LOG_CRIT, ERROR_MEM_ALLOC);
       }
 
-      if (CTX->result == DSR_ISSPAM)
-      {
+// FreeBSD patch: put the user in all emails, extremely usefull for scripts
+//      if (CTX->result == DSR_ISSPAM)
+//      {
         snprintf(data, sizeof(data), "X-DSPAM-User: %s", CTX->username);
         head = _ds_create_header_field(data);
         if (head != NULL)
@@ -2556,7 +2557,7 @@
         }
         else
           LOG (LOG_CRIT, ERROR_MEM_ALLOC);
-      }
+//      }  // end of FreeBSD patch
 
       if (!strcmp(_ds_pref_val(PTX, "showFactors"), "on")) {

