--- src/register.c.orig	Sat Jan  8 11:05:12 2005
+++ src/register.c	Sat Apr  9 16:16:48 2005
@@ -35,7 +35,7 @@
 #include "siproxd.h"
 #include "log.h"
 
-static char const ident[]="$Id: register.c,v 1.46 2005/01/08 10:05:12 hb9xar Exp $";
+static char const ident[]="$Id: register.c,v 1.50 2005/04/03 20:55:30 hb9xar Exp $";
 
 /* configuration storage */
 extern struct siproxd_config configuration;
@@ -255,7 +255,7 @@
     */
    if (expires > 0) {
       /*
-       * First make sure, we have a prober Contact header:
+       * First make sure, we have a proper Contact header:
        *  - url
        *  - url -> hostname
        *
@@ -367,57 +367,56 @@
                                     strlen(configuration.masked_host.string[j])+1);
             strcpy(urlmap[i].masq_url->host, configuration.masked_host.string[j]);
          }
-
+      } else { /* if new entry */
+         /* This is an existing entry */
          /*
-          * for transparent proxying: force device to be masqueraded
-          * as with the outbound IP
+          * Some phones (like BudgeTones *may* dynamically grab a SIP port
+          * so we might want to update the true_url and reg_url each time
+          * we get an REGISTER
           */
-         if (force_lcl_masq) {
-            struct in_addr addr;
-            char *addrstr;
-
-            if (get_ip_by_ifname(configuration.outbound_if, &addr) !=
-                STS_SUCCESS) {
-               ERROR("can't find outbound interface %s - configuration error?",
-                     configuration.outbound_if);
-               return STS_FAILURE;
-            }
-
-            /* host part */
-            addrstr = utils_inet_ntoa(addr);
-            DEBUGC(DBCLASS_REG,"masquerading UA %s@%s local %s@%s",
-                   (url1_contact->username) ? url1_contact->username : "*NULL*",
-                   (url1_contact->host) ? url1_contact->host : "*NULL*",
-                   (url1_contact->username) ? url1_contact->username : "*NULL*",
-                   addrstr);
-            urlmap[i].masq_url->host=realloc(urlmap[i].masq_url->host,
-                                             strlen(addrstr)+1);
-            strcpy(urlmap[i].masq_url->host, addrstr);
 
-            /* port number if required */
-            if (configuration.sip_listen_port != SIP_PORT) {
-               urlmap[i].masq_url->port=realloc(urlmap[i].masq_url->port, 16);
-               sprintf(urlmap[i].masq_url->port, "%i",
-                       configuration.sip_listen_port);
-            }
-         }
-
-      } else { /* if new entry */
-      /*
-       * Some phones (like BudgeTones *may* dynamically grab a SIP port
-       * so we might want to update the true_url and reg_url each time
-       * we get an REGISTER
-       */
-         /* Contact: field */
+         /* Contact: field (true_url) */
          osip_uri_free(urlmap[i].true_url);
          osip_uri_clone( ((osip_contact_t*)
                          (ticket->sipmsg->contacts->node->element))->url, 
-        	         &urlmap[i].true_url);
-         /* To: field */
+                         &urlmap[i].true_url);
+         /* To: field (reg_url) */
          osip_uri_free(urlmap[i].reg_url);
          osip_uri_clone( ticket->sipmsg->to->url, 
-        	    &urlmap[i].reg_url);
+                         &urlmap[i].reg_url);
       }
+
+      /*
+       * for proxying: force device to be masqueraded
+       * as with the outbound IP (masq_url)
+       */
+      if (force_lcl_masq) {
+         struct in_addr addr;
+         char *addrstr;
+
+         if (get_interface_ip(IF_OUTBOUND, &addr) != STS_SUCCESS) {
+            return STS_FAILURE;
+         }
+
+         /* host part */
+         addrstr = utils_inet_ntoa(addr);
+         DEBUGC(DBCLASS_REG,"masquerading UA %s@%s local %s@%s",
+                (url1_contact->username) ? url1_contact->username : "*NULL*",
+                (url1_contact->host) ? url1_contact->host : "*NULL*",
+                (url1_contact->username) ? url1_contact->username : "*NULL*",
+                addrstr);
+         urlmap[i].masq_url->host=realloc(urlmap[i].masq_url->host,
+                                          strlen(addrstr)+1);
+         strcpy(urlmap[i].masq_url->host, addrstr);
+
+         /* port number if required */
+         if (configuration.sip_listen_port != SIP_PORT) {
+            urlmap[i].masq_url->port=realloc(urlmap[i].masq_url->port, 16);
+            sprintf(urlmap[i].masq_url->port, "%i",
+                    configuration.sip_listen_port);
+         }
+      }
+
       /* give some safety margin for the next update */
       if (expires > 0) expires+=30;
 
@@ -495,6 +494,7 @@
    osip_via_t *via;
    int port;
    char *buffer;
+   int buflen;
    struct in_addr addr;
    osip_header_t *expires_hdr;
 
@@ -550,7 +550,7 @@
       }
    }   
 
-   sts = osip_message_to_str(response, &buffer);
+   sts = osip_message_to_str(response, &buffer, &buflen);
    if (sts != 0) {
       ERROR("register_response: msg_2char failed");
       return STS_FAILURE;
@@ -563,7 +563,7 @@
       port=configuration.sip_listen_port;
    }
 
-   sipsock_send(addr, port, ticket->protocol, buffer, strlen(buffer));
+   sipsock_send(addr, port, ticket->protocol, buffer, buflen);
 
    /* free the resources */
    osip_message_free(response);
