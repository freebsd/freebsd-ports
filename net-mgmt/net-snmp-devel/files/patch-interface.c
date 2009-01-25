--- agent/mibgroup/if-mib/data_access/interface.c.orig	2009-01-25 17:49:04.000000000 +0900
+++ agent/mibgroup/if-mib/data_access/interface.c	2009-01-25 17:49:57.000000000 +0900
@@ -775,7 +775,7 @@
     netsnmp_conf_if_list   *if_ptr = conf_list, *if_next;
     while (if_ptr) {
         if_next = if_ptr->next;
-        free(if_ptr->name);
+        free((void*)if_ptr->name);
         free(if_ptr);
         if_ptr = if_next;
     }
