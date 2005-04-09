--- src/proxy.c.orig	Mon Jan 24 20:12:40 2005
+++ src/proxy.c	Sat Apr  9 16:01:02 2005
@@ -35,7 +35,7 @@
 #include "siproxd.h"
 #include "log.h"
 
-static char const ident[]="$Id: proxy.c,v 1.80 2005/01/24 19:12:40 hb9xar Exp $";
+static char const ident[]="$Id: proxy.c,v 1.85 2005/03/27 16:05:16 hb9xar Exp $";
 
 /* configuration storage */
 extern struct siproxd_config configuration;	/* defined in siproxd.c */
@@ -81,6 +81,7 @@
    osip_uri_t *url;
    int port;
    char *buffer;
+   int buflen;
    osip_message_t *request;
    struct sockaddr_in *from;
 
@@ -516,14 +517,14 @@
    * RFC 3261, Section 16.6 step 10
    * Proxy Behavior - Forward the new request
    */
-   sts = osip_message_to_str(request, &buffer);
+   sts = osip_message_to_str(request, &buffer, &buflen);
    if (sts != 0) {
       ERROR("proxy_request: osip_message_to_str failed");
       return STS_FAILURE;
    }
 
    sipsock_send(sendto_addr, port, ticket->protocol,
-                buffer, strlen(buffer)); 
+                buffer, buflen); 
    osip_free (buffer);
 
   /*
@@ -565,6 +566,7 @@
    osip_via_t *via;
    int port;
    char *buffer;
+   int buflen;
    osip_message_t *response;
    struct sockaddr_in *from;
 
@@ -669,8 +671,8 @@
    (e.g 1393xxx@proxy01.sipphone.com for calls made sipphone -> FWD)
    How can we deal with this? Should I take into consideration the 'Via'
    headers? This is the only clue I have, pointing to the *real* UA.
-   Maybe I should put in a 'siproxd' ftag value to recognize it a header
-   put in by myself
+   Maybe I should put in a 'siproxd' ftag value to recognize it as a header
+   inserted by myself
 */
    if ((type == 0) && (!osip_list_eol(response->vias, 0))) {
       osip_via_t *via;
@@ -910,14 +912,14 @@
       }
    }
 
-   sts = osip_message_to_str(response, &buffer);
+   sts = osip_message_to_str(response, &buffer, &buflen);
    if (sts != 0) {
       ERROR("proxy_response: osip_message_to_str failed");
       return STS_FAILURE;
    }
 
    sipsock_send(sendto_addr, port, ticket->protocol,
-                buffer, strlen(buffer)); 
+                buffer, buflen); 
    osip_free (buffer);
    return STS_SUCCESS;
 }
@@ -938,6 +940,7 @@
    struct in_addr map_addr, addr_sess, addr_media, outside_addr, inside_addr;
    int sts;
    char *bodybuff;
+   int bodybuflen;
    char clen[8]; /* content length: probably never more than 7 digits !*/
    int map_port, msg_port;
    int media_stream_no;
@@ -966,25 +969,31 @@
       }
    }
 
-   sts = osip_body_to_str(body, &bodybuff);
+   sts = osip_body_to_str(body, &bodybuff, &bodybuflen);
+   if (sts != 0) {
+      ERROR("rewrite_invitation_body: unable to osip_body_to_str");
+   }
    sts = sdp_message_init(&sdp);
    sts = sdp_message_parse (sdp, bodybuff);
-   osip_free(bodybuff);
    if (sts != 0) {
       ERROR("rewrite_invitation_body: unable to sdp_message_parse body");
+      DUMP_BUFFER(-1, bodybuff, bodybuflen);
+      osip_free(bodybuff);
       sdp_message_free(sdp);
       return STS_FAILURE;
    }
+   osip_free(bodybuff);
 
 
 if (configuration.debuglevel)
 { /* just dump the buffer */
    char *tmp, *tmp2;
+   int tmplen;
    sts = osip_message_get_body(mymsg, 0, &body);
-   sts = osip_body_to_str(body, &tmp);
+   sts = osip_body_to_str(body, &tmp, &tmplen);
    osip_content_length_to_str(mymsg->content_length, &tmp2);
    DEBUG("Body before rewrite (clen=%s, strlen=%i):\n%s\n----",
-         tmp2, strlen(tmp), tmp);
+         tmp2, tmplen, tmp);
    osip_free(tmp);
    osip_free(tmp2);
 }
@@ -995,22 +1004,16 @@
     */
 
    /* get outbound address */
-   if (get_ip_by_ifname(configuration.outbound_if, &outside_addr) != 
-       STS_SUCCESS) {
-      ERROR("can't find outbound interface %s - configuration error?",
-            configuration.outbound_if);
+   if (get_interface_ip(IF_OUTBOUND, &outside_addr) != STS_SUCCESS) {
       sdp_message_free(sdp);
       return STS_FAILURE;
    }
 
    /* get inbound address */
-   if (get_ip_by_ifname(configuration.inbound_if, &inside_addr) !=
-       STS_SUCCESS) {
-      ERROR("can't find inbound interface %s - configuration error?",
-             configuration.inbound_if);
+   if (get_interface_ip(IF_INBOUND, &inside_addr) != STS_SUCCESS) {
       sdp_message_free(sdp);
-       return STS_FAILURE;
-    }
+      return STS_FAILURE;
+   }
 
    /* figure out what address to use for RTP masquerading */
    if (MSG_IS_REQUEST(mymsg)) {
@@ -1081,7 +1084,6 @@
        * Rewrite
        * an IP address of 0.0.0.0 means *MUTE*, don't rewrite such
        */
-      /*&&&& should use gethostbyname here */
       if (strcmp(sdp->c_connection->c_addr, "0.0.0.0") != 0) {
          osip_free(sdp->c_connection->c_addr);
          sdp->c_connection->c_addr=osip_malloc(HOSTNAME_SIZE);
@@ -1126,7 +1128,6 @@
       have_c_media=0;
       sdp_conn=sdp_message_connection_get(sdp, media_stream_no, 0);
       if (sdp_conn && sdp_conn->c_addr) {
-         /*&&&& should use gethostbyname here as well */
          if (strcmp(sdp_conn->c_addr, "0.0.0.0") != 0) {
             sts = get_ip_by_host(sdp_conn->c_addr, &addr_media);
             have_c_media=1;
@@ -1170,6 +1171,19 @@
                memcpy(&addr_media, &addr_sess, sizeof(addr_sess));
             }
 
+            /*
+             * Am I running in front of the routing device? Then I cannot
+             * use the external IP to bind a listen socket to, so force
+             * the use of my inbound IP for listening.
+             */
+            if ((rtp_direction == DIR_INCOMING) &&
+                (configuration.outbound_host) &&
+                (strcmp(configuration.outbound_host, "")!=0)) {
+               DEBUGC(DBCLASS_PROXY, "proxy_rewrite_invitation_body: "
+                      "in-front-of-NAT-Router");
+               memcpy(&map_addr, &inside_addr, sizeof (map_addr));
+            }
+
             sts = rtp_start_fwd(osip_message_get_call_id(mymsg),
                                 client_id,
                                 rtp_direction,
@@ -1205,17 +1219,21 @@
 
    /* dump new body */
    sdp_message_to_str(sdp, &bodybuff);
+   bodybuflen=strlen(bodybuff);
 
    /* free sdp structure */
    sdp_message_free(sdp);
 
    /* include new body */
-   osip_message_set_body(mymsg, bodybuff);
+   osip_message_set_body(mymsg, bodybuff, bodybuflen);
+   if (sts != 0) {
+      ERROR("rewrite_invitation_body: unable to osip_message_set_body body");
+   }
 
    /* free content length resource and include new one*/
    osip_content_length_free(mymsg->content_length);
    mymsg->content_length=NULL;
-   sprintf(clen,"%i",strlen(bodybuff));
+   sprintf(clen,"%i",bodybuflen);
    sts = osip_message_set_content_length(mymsg, clen);
 
    /* free old body */
@@ -1224,11 +1242,12 @@
 if (configuration.debuglevel)
 { /* just dump the buffer */
    char *tmp, *tmp2;
+   int tmplen;
    sts = osip_message_get_body(mymsg, 0, &body);
-   sts = osip_body_to_str(body, &tmp);
+   sts = osip_body_to_str(body, &tmp, &tmplen);
    osip_content_length_to_str(mymsg->content_length, &tmp2);
    DEBUG("Body after rewrite (clen=%s, strlen=%i):\n%s\n----",
-         tmp2, strlen(tmp), tmp);
+         tmp2, tmplen, tmp);
    osip_free(tmp);
    osip_free(tmp2);
 }
