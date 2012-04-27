--- ./agent/mibgroup/agent/extend.c.orig	2011-09-28 00:53:47.000000000 -0400
+++ ./agent/mibgroup/agent/extend.c	2012-04-26 22:32:10.000000000 -0400
@@ -1380,6 +1380,10 @@
                  * Determine which line we've been asked for....
                  */
                 line_idx = *table_info->indexes->next_variable->val.integer;
+                if (line_idx < 1 || line_idx > extension->numlines) {
+                    netsnmp_set_request_error(reqinfo, request, SNMP_NOSUCHINSTANCE);
+                    continue;
+                }
                 cp  = extension->lines[line_idx-1];
 
                 /* 
