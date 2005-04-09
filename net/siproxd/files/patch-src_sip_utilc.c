--- src/sip_utils.c.orig	Sat Jan  8 11:05:13 2005
+++ src/sip_utils.c	Sat Apr  9 16:19:28 2005
@@ -43,7 +43,7 @@
 #include "rewrite_rules.h"
 #include "log.h"
 
-static char const ident[]="$Id: sip_utils.c,v 1.34 2005/01/08 10:05:13 hb9xar Exp $";
+static char const ident[]="$Id: sip_utils.c,v 1.37 2005/03/01 21:36:48 hb9xar Exp $";
 
 
 /* configuration storage */
@@ -174,11 +174,8 @@
 int is_via_local (osip_via_t *via) {
    int sts, found;
    struct in_addr addr_via, addr_myself;
-   char *my_interfaces[]=
-        { configuration.inbound_if,  configuration.outbound_if,  (char*)-1 };
    int port;
    int i;
-   char *ptr;
 
    if (via==NULL) {
       ERROR("called is_via_local with NULL via");
@@ -197,19 +194,14 @@
    }   
 
    found=0;
-   for (i=0; ; i++) {
+   for (i=0; i<2; i++) {
       /*
-       * try to search by interface name first
+       * search my in/outbound interfaces
        */
-      ptr=my_interfaces[i];
-      if (ptr==(char*)-1) break; /* end of list mark */
-
-      if (ptr) {
-         DEBUGC(DBCLASS_BABBLE,"resolving IP of interface %s",ptr);
-         if (get_ip_by_ifname(ptr, &addr_myself) != STS_SUCCESS) {
-            ERROR("can't find interface %s - configuration error?", ptr);
-            continue;
-         }
+      DEBUGC(DBCLASS_BABBLE,"resolving IP of interface %s",
+             (i==IF_INBOUND)? "inbound":"outbound");
+      if (get_interface_ip(i, &addr_myself) != STS_SUCCESS) {
+         continue;
       }
 
       /* check the extracted VIA against my own host addresses */
@@ -390,11 +382,8 @@
    osip_message_t *sip=ticket->sipmsg;
    int found;
    struct in_addr addr_uri, addr_myself;
-   char *my_interfaces[]=
-        { configuration.inbound_if,  configuration.outbound_if,  (char*)-1 };
    int port;
    int i;
-   char *ptr;
 
    if (sip==NULL) {
       ERROR("called is_sipuri_local with NULL sip");
@@ -416,19 +405,14 @@
    }   
 
    found=0;
-   for (i=0; ; i++) {
+   for (i=0; i<2; i++) {
       /*
-       * try to search by interface name first
+       * search my in/outbound interfaces
        */
-      ptr=my_interfaces[i];
-      if (ptr==(char*)-1) break; /* end of list mark */
-
-      if (ptr) {
-         DEBUGC(DBCLASS_BABBLE,"resolving IP of interface %s",ptr);
-         if (get_ip_by_ifname(ptr, &addr_myself) != STS_SUCCESS) {
-            ERROR("can't find interface %s - configuration error?", ptr);
-            continue;
-         }
+      DEBUGC(DBCLASS_BABBLE,"resolving IP of interface %s",
+             (i==IF_INBOUND)? "inbound":"outbound");
+      if (get_interface_ip(i, &addr_myself) != STS_SUCCESS) {
+         continue;
       }
 
       /* check the extracted HOST against my own host addresses */
@@ -533,6 +517,7 @@
    osip_via_t *via;
    int port;
    char *buffer;
+   int buflen;
    struct in_addr addr;
 
    /* create the response template */
@@ -563,7 +548,7 @@
       }
    }   
 
-   sts = osip_message_to_str(response, &buffer);
+   sts = osip_message_to_str(response, &buffer, &buflen);
    if (sts != 0) {
       ERROR("sip_gen_response: msg_2char failed");
       return STS_FAILURE;
@@ -577,7 +562,7 @@
    }
 
    /* send to destination */
-   sipsock_send(addr, port, ticket->protocol, buffer, strlen(buffer));
+   sipsock_send(addr, port, ticket->protocol, buffer, buflen);
 
    /* free the resources */
    osip_message_free(response);
@@ -601,25 +586,26 @@
    osip_via_t *via;
    int sts;
    char branch_id[VIA_BRANCH_SIZE];
+   char *myaddr;
 
-   if (interface == IF_OUTBOUND) {
-      if (get_ip_by_ifname(configuration.outbound_if, &addr) != STS_SUCCESS) {
-         ERROR("can't find interface %s - configuration error?",
-               configuration.outbound_if);
-         return STS_FAILURE;
-      }
-   } else {
-      if (get_ip_by_ifname(configuration.inbound_if, &addr) != STS_SUCCESS) {
-         ERROR("can't find inbound interface %s - configuration error?",
-               configuration.inbound_if);
-         return STS_FAILURE;
-      }
+   if (get_interface_ip(interface, &addr) != STS_SUCCESS) {
+      return STS_FAILURE;
    }
 
    sts = sip_calculate_branch_id(ticket, branch_id);
 
-   sprintf(tmp, "SIP/2.0/UDP %s:%i;branch=%s;", utils_inet_ntoa(addr),
-           configuration.sip_listen_port, branch_id);
+   myaddr=utils_inet_ntoa(addr);
+//&&&&
+#if 0
+   sprintf(tmp, "SIP/2.0/UDP %s:%i;branch=%s;sent-by=%s:%i",
+           myaddr, configuration.sip_listen_port,
+           branch_id,
+           myaddr, configuration.sip_listen_port);
+#else
+   sprintf(tmp, "SIP/2.0/UDP %s:%i;branch=%s",
+           myaddr, configuration.sip_listen_port,
+           branch_id);
+#endif
    DEBUGC(DBCLASS_BABBLE,"adding VIA:%s",tmp);
 
    sts = osip_via_init(&via);
