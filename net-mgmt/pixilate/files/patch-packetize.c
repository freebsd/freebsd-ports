--- /home/krion/packetize.c	Thu Apr 15 09:32:58 2004
+++ packetize.c	Fri Mar 26 03:29:20 2004
@@ -1,6 +1,7 @@
 /*    packetize.c
- *    Copyright 2002-2003 Kirby Kuehl (vacuum@users.sourceforge.net)
- *    This file is part of pixilate http://winfingerprint.sourceforge.net/pixilate.php
+ *    Copyright 2002-2004 Kirby Kuehl (vacuum@users.sourceforge.net)
+ *    This file is part of pixilate
+ *    http://winfingerprint.sourceforge.net/pixilate.php
  *
  *    pixilate is free software; you can redistribute it and/or modify
  *    it under the terms of the GNU General Public License as published by
@@ -66,24 +67,15 @@
 
                 icmp_header_len = LIBNET_ICMPV4_ECHO_H;
                 break;
-            case 3: // icmp type 3 literal unreachable
+            case 3: /* icmp type 3 literal unreachable */
                 icmp = libnet_build_icmpv4_unreach(
-                    ICMP_UNREACH,                      //type 
-                    ICMP_UNREACH_PORT,                 // code 
-                    0,                                 // 0 libnet calculate checksum
-                    LIBNET_IPV4_H + LIBNET_UDP_H,      // original ip header id
-                    IPTOS_LOWDELAY | IPTOS_THROUGHPUT, // original ip header frag info
-                    pacl->id,                          // o IP ID 
-                    0,                                 // o frag 
-                    64,                                // o TTL 
-                    IPPROTO_UDP,                       // o protocol 
-                    0x7012,                            // o checksum 
-                    pacl->source_addr,                 // o source IP 
-                    pacl->destination_addr,            // o destination IP 
-                    pacl->payload,                     // payload 
-                    pacl->payload_s,                   // payload size 
-                    l,                                 // libnet handle 
-                    0);                                //create new ptag
+                    ICMP_UNREACH,             /* type */ 
+                    ICMP_UNREACH_PORT,        /* code */
+                    0,                        /* 0 libnet calculate checksum */
+                    pacl->payload,            /* payload */ 
+                    pacl->payload_s,          /* payload size */
+                    l,                        /* libnet handle */
+                    0);                       /* 0 create new ptag */
                 if(icmp == -1)
                     fprintf(stderr,"Unable to build icmp unreach packet :%s\n",
                         libnet_geterror(l));
@@ -92,25 +84,16 @@
 
                 icmp_header_len = LIBNET_ICMPV4_UNREACH_H;
                 break;
-            case 5: // icmp type 5 literal redirect
+            case 5: /* icmp type 5 literal redirect */
                 icmp =  libnet_build_icmpv4_redirect(
-                    ICMP_REDIRECT,          //type  
-                    ICMP_UNREACH_HOST,      //code 
-                    0,                  //0 lets libnet calculate checksum
-                    pacl->gateway_addr,     // gateway
-                    LIBNET_TCP_H,           // orig_len
-                    IPTOS_LOWDELAY | IPTOS_THROUGHPUT, //original TOS
-                    111,                    // orig_id
-                    0,                      // orig_frag
-                    64,                     // orig_ttl
-                    IPPROTO_TCP,            // original protocol
-                    0,                      // orig_checksum shouldnt be 0
-                    pacl->source_addr,      // orig_src
-                    pacl->destination_addr, // orig_dst
-                    pacl->payload,          // payload
-                    pacl->payload_s,        // payload size
-                    l,                      // libnet handle
-                    0);                     // create new ptag
+                    ICMP_REDIRECT,          /* type */  
+                    ICMP_UNREACH_HOST,      /* code */ 
+                    0,              /*0 lets libnet calculate checksum */
+                    pacl->gateway_addr,     /* gateway */
+                    pacl->payload,          /* payload */
+                    pacl->payload_s,        /* payload size */
+                    l,                      /* libnet handle */
+                    0);                     /* 0 create new ptag */
                 icmp_header_len = LIBNET_ICMPV4_REDIRECT_H;
                 break;
             case 8: // icmp type 8 literal echo
@@ -132,24 +115,15 @@
 
                 icmp_header_len = LIBNET_ICMPV4_ECHO_H;
                 break;
-            case 11: // icmp type 11 literal time-exceeded
+            case 11: /* icmp type 11 literal time-exceeded */
                 icmp = libnet_build_icmpv4_timeexceed(
-                    ICMP_TIMXCEED,          //type 
-                    ICMP_TIMXCEED_INTRANS,  //code
-                    0,                      // 0 lets libnet calculate checksum
-                    LIBNET_TCP_H,           // original length
-                    IPTOS_LOWDELAY | IPTOS_THROUGHPUT, //original TOS
-                    111,                    // original header id
-                    0,                      // original header fragmentation
-                    64,                     // original TTL
-                    IPPROTO_TCP,            // original protocol 
-                    0,                      // original checksum (shouldnt be 0)
-                    pacl->source_addr,      // original source address
-                    pacl->destination_addr, // original destination address
-                    pacl->payload,          // payload
-                    pacl->payload_s,        // payload size
-                    l,                      // libnet handle
-                    0);                     // create new ptag
+                    ICMP_TIMXCEED,          /* type */ 
+                    ICMP_TIMXCEED_INTRANS,  /* code */
+                    0,                  /* 0 lets libnet calculate checksum */
+                    pacl->payload,          /* payload */
+                    pacl->payload_s,        /* payload size */
+                    l,                      /* libnet handle */
+                    0);                     /* create new ptag */
                 icmp_header_len = LIBNET_ICMPV4_TIMXCEED_H;
                 break;
             case 13: // icmp type 13 literal timestamp-reply
@@ -433,7 +407,8 @@
                   0       // packet id 
                   );
                
-               break; */
+               break;
+*/
             default: // try our best to generate "other" protocols automatically
                if(pacl->protocol == 41)
                {
