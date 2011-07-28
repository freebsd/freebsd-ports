--- ./agent/auto_nlist.c.orig	2011-07-07 15:38:44.000000000 -0700
+++ agent/auto_nlist.c	2011-07-07 15:39:37.000000000 -0700
@@ -66,15 +66,26 @@
         strcpy(it->nl[0].n_name, string);
         it->nl[0].n_name[strlen(string)+1] = '\0';
 #else
-        sprintf(it->nl[0].n_name, "_%s", string);
+        char *n_name;
+
+        n_name = malloc(strlen(string) + 2);
+        if (n_name == NULL) {
+            snmp_log(LOG_ERR, "nlist err: failed to allocate memory");
+            return (-1);
+        }
+        snprintf(n_name, strlen(string) + 2, "_%s", string);
+        it->nl[0].n_name = (const char*)n_name;
 #endif
         it->nl[1].n_name = 0;
         init_nlist(it->nl);
 #if !(defined(aix4) || defined(aix5) || defined(aix6) || defined(aix7) || \
                     defined(netbsd1) || defined(dragonfly)) 
         if (it->nl[0].n_type == 0) {
-            strcpy(it->nl[0].n_name, string);
-            it->nl[0].n_name[strlen(string)+1] = '\0';
+            it->nl[0].n_name = (const char*)strdup(string);
+            if (it->nl[0].n_name == (const char*)NULL) {
+                snmp_log(LOG_ERR, "nlist err: failed to allocate memory");
+                return (-1);
+            }
             init_nlist(it->nl);
         }
 #endif
