--- src/siproxd.c.orig	Sat Jan  8 11:41:46 2005
+++ src/siproxd.c	Sat Apr  9 15:50:49 2005
@@ -38,7 +38,7 @@
 #include "siproxd.h"
 #include "log.h"
 
-static char const ident[]="$Id: siproxd.c,v 1.57 2005/01/08 10:41:46 hb9xar Exp $";
+static char const ident[]="$Id: siproxd.c,v 1.60 2005/03/01 21:36:48 hb9xar Exp $";
 
 /* configuration storage */
 struct siproxd_config configuration;
@@ -82,6 +82,7 @@
 {
    int sts;
    int i;
+   int buflen;
    int access;
    char buff [BUFFER_SIZE];
    sip_ticket_t ticket;
@@ -291,8 +292,9 @@
       /* got input, process */
       DEBUGC(DBCLASS_BABBLE,"back from sipsock_wait");
 
-      i=sipsock_read(&buff, sizeof(buff)-1, &ticket.from, &ticket.protocol);
-      buff[i]='\0';
+      buflen=sipsock_read(&buff, sizeof(buff)-1, &ticket.from,
+                           &ticket.protocol);
+      buff[buflen]='\0';
 
       /* evaluate the access lists (IP based filter)*/
       access=accesslist_check(ticket.from);
@@ -302,7 +304,7 @@
       }
 
       /* integrity checks */
-      sts=security_check_raw(buff, i);
+      sts=security_check_raw(buff, buflen);
       if (sts != STS_SUCCESS) {
          DEBUGC(DBCLASS_SIP,"security check (raw) failed");
          continue; /* there are no resources to free */
@@ -321,10 +323,10 @@
        * Proxy Behavior - Request Validation - Reasonable Syntax
        * (parse the received message)
        */
-      sts=osip_message_parse(ticket.sipmsg, buff);
+      sts=osip_message_parse(ticket.sipmsg, buff, buflen);
       if (sts != 0) {
          ERROR("osip_message_parse() failed... this is not good");
-         DUMP_BUFFER(-1, buff, i);
+         DUMP_BUFFER(-1, buff, buflen);
          goto end_loop; /* skip and free resources */
       }
 
@@ -332,7 +334,7 @@
       sts=security_check_sip(&ticket);
       if (sts != STS_SUCCESS) {
          ERROR("security_check_sip() failed... this is not good");
-         DUMP_BUFFER(-1, buff, i);
+         DUMP_BUFFER(-1, buff, buflen);
          goto end_loop; /* skip and free resources */
       }
 
@@ -422,10 +424,8 @@
             dest_port= (url->port)?atoi(url->port):SIP_PORT;
 
             if ( (get_ip_by_host(url->host, &addr1) == STS_SUCCESS) &&
-                 (get_ip_by_ifname(configuration.inbound_if,&addr2) ==
-                  STS_SUCCESS) &&
-                 (get_ip_by_ifname(configuration.outbound_if,&addr3) ==
-                  STS_SUCCESS)) {
+                 (get_interface_ip(IF_INBOUND,&addr2) == STS_SUCCESS) &&
+                 (get_interface_ip(IF_OUTBOUND,&addr3) == STS_SUCCESS)) {
 
                if ((configuration.sip_listen_port == dest_port) &&
                    ((memcmp(&addr1, &addr2, sizeof(addr1)) == 0) ||
@@ -455,7 +455,7 @@
        * If not, send back error to UA and
        * skip any proxying attempt
        */
-      } else if (get_ip_by_ifname(configuration.outbound_if,NULL) !=
+      } else if (get_interface_ip(IF_OUTBOUND,NULL) !=
                  STS_SUCCESS) {
          DEBUGC(DBCLASS_SIP, "got a %s to proxy, but outbound interface "
                 "is down", (MSG_IS_REQUEST(ticket.sipmsg))? "REQ" : "RES");
