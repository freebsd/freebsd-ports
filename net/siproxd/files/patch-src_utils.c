--- src/utils.c.orig	Sat Jan  8 11:05:13 2005
+++ src/utils.c	Tue Mar  1 22:36:48 2005
@@ -44,7 +44,7 @@
 #include "siproxd.h"
 #include "log.h"
 
-static char const ident[]="$Id: utils.c,v 1.41 2005/01/08 10:05:13 hb9xar Exp $";
+static char const ident[]="$Id: utils.c,v 1.42 2005/03/01 21:36:48 hb9xar Exp $";
 
 /* configuration storage */
 extern struct siproxd_config configuration;
@@ -288,6 +288,48 @@
 	        passwd->pw_uid, (sts==0)?"Ok":"Failed");
       }
    }
+}
+
+
+/*
+ * get_interface_ip:
+ * fetches own IP address by interface INBOUND/OUTBOUND
+ *
+ * STS_SUCCESS on returning a valid IP and interface is UP
+ * STS_FAILURE if interface is DOWN or other problem
+ */
+int  get_interface_ip(int interface, struct in_addr *retaddr) {
+   int sts=STS_FAILURE;
+   char *tmp=NULL;
+
+      if (interface == IF_INBOUND) {
+         tmp = configuration.inbound_if;
+      } else if (interface == IF_OUTBOUND) {
+         tmp = configuration.outbound_if;
+      }
+
+   if ((interface == IF_OUTBOUND) && 
+              (configuration.outbound_host) &&
+              (strcmp(configuration.outbound_host, "")!=0)) {
+      DEBUGC(DBCLASS_DNS, "fetching outbound IP by HOSTNAME");
+      if (retaddr) {
+         sts = get_ip_by_host(configuration.outbound_host, retaddr);
+      } else {
+         sts = STS_SUCCESS;
+      }
+
+   } else if (tmp && (strcmp(tmp, "")!=0)) {
+      DEBUGC(DBCLASS_DNS, "fetching interface IP by INTERFACE [%i]", interface);
+      sts = get_ip_by_ifname(tmp, retaddr);
+      if (sts != STS_SUCCESS) {
+         ERROR("can't find interface %s - configuration error?", tmp);
+      }
+
+   } else {
+      ERROR("Don't know what interface to look for - configuration error?");
+   }
+
+   return sts;
 }
 
 
