--- server-src/amadmin.c.orig	2011-06-25 22:52:23.000000000 +0200
+++ server-src/amadmin.c	2011-06-25 22:53:50.000000000 +0200
@@ -1414,7 +1414,7 @@
                 amfree(dumpstr);
 		dumpfile_free_data(&file);
             }
-            g_slist_free_full(file_list);
+            _slist_free_full(file_list, g_free);
             break;
 
         case HOLDING_DELETE:
@@ -1432,7 +1432,7 @@
                     error(_("Could not delete '%s'"), (char *)li->data);
                 }
             }
-            g_slist_free_full(file_list);
+            _slist_free_full(file_list, g_free);
             break;
     }
 }
