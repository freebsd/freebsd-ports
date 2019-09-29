--- agent/mibgroup/if-mib/data_access/interface_sysctl.c.orig	2018-07-16 16:33:40 UTC
+++ agent/mibgroup/if-mib/data_access/interface_sysctl.c
@@ -531,8 +531,11 @@
                 }
             }
             adl = (struct sockaddr_dl *) a;
-            if_name = (char *) adl->sdl_data;
-            if_name[adl->sdl_nlen] = '\0';
+            if_name = malloc(adl->sdl_nlen + 1);
+            if (if_name) {
+                memcpy(if_name, adl->sdl_data, adl->sdl_nlen);
+                if_name[adl->sdl_nlen] = '\0';
+            }
         }
         if (!(ifp->ifm_addrs & RTA_IFP) || if_name == NULL) {
             snmp_log(LOG_ERR, "ifm_index %u: no interface name in message, "
@@ -541,6 +544,7 @@
         }
 
         entry = netsnmp_access_interface_entry_create(if_name, ifp->ifm_index);
+        free(if_name);
         if(NULL == entry) {
             netsnmp_access_interface_container_free(container,
                                                     NETSNMP_ACCESS_INTERFACE_FREE_NOFLAGS);
