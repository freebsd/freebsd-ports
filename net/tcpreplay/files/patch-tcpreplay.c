--- tcpreplay.c.orig	Fri May 17 17:55:47 2002
+++ tcpreplay.c	Fri May 31 11:42:37 2002
@@ -65,6 +65,7 @@
 #include <regex.h>
 #include <math.h>
 #include "cache.h"
+#include "cidr.h"
 
 #define TCPREPLAY_VERSION "1.0.1-adt9"
 
@@ -85,6 +86,10 @@
 u_int start = 0;
 u_int stop = 0;
 int mode;
+int regex_mode;
+int cidr_mode;
+int cache_mode;
+int nomartians = 0;
 int rate;
 int debug;
 float multiplier;
@@ -101,6 +106,9 @@
 CACHE * cachedata = NULL;
 int cache_bit = 0;
 int cache_byte = 0;
+struct libnet_link_int * write_if; // Primary interface -i
+struct libnet_link_int * write_if2;  // Secondary interface -j
+CIDR * cidrdata = NULL;
 
 void usage(){
   fprintf(stderr, "Version: " TCPREPLAY_VERSION "\nUsage: tcpreplay "
@@ -244,6 +252,7 @@
   struct libnet_ethernet_hdr * eth_hdr;
 #ifdef DEBUG
   int regex_match = -1;
+  int cache_match = -1;
   int cidr_match = -1;
 #endif
   size_t nmatch = 0;
@@ -257,7 +266,7 @@
      make sure we're inside that slice, or increment the cache 
      pointers, and return without further processing
   */
-  if (start != 0) {
+  if ((start != 0) && cache_mode) {
     if (!((start <= packet_num) && (packet_num <= stop))) {
       if (cache_bit == 7) {
 	cache_bit = 0;
@@ -359,14 +368,22 @@
     if (interface2 == NULL) {
       /* we're not using a second NIC so just write the packet all normal like */
 
-      write_status = libnet_write_link_layer((struct libnet_link_int *)user, 
+      write_status = libnet_write_link_layer((struct libnet_link_int *)write_if, 
 					     interface, data, pcap_hdr->caplen);
     } 
     
     else { /* we're in multi-nic mode, and have to figure things out */
-      if (mode == REGEX_MODE) {
+      if (regex_mode == 1) {
 	/* put the source ip of the packet into src_ip in x.x.x.x format */
 	ip_hdr = (struct libnet_ip_hdr *) (data + LIBNET_ETH_H);
+	/* drop martians */
+	if (nomartians == 1) {
+	   switch ((ntohl(ip_hdr->ip_dst.s_addr) & 0xff000000) >> 24) {
+           case 0: case 127: case 255:
+              write_status=1;
+	      continue;
+           }
+        }
 	memset (src_ip, '\0', 16);
 	strncat (src_ip, libnet_host_lookup(ip_hdr->ip_src.s_addr, RESOLVE), 15);
 	
@@ -384,7 +401,7 @@
 	  if (primary_mac != NULL)
 	    memcpy(eth_hdr->ether_dhost, primary_mac, ETHER_ADDR_LEN);
 
-	  write_status = libnet_write_link_layer((struct libnet_link_int *)user,
+	  write_status = libnet_write_link_layer((struct libnet_link_int *)write_if,
 						 interface, data, pcap_hdr->caplen);
 	} 
 	
@@ -396,11 +413,53 @@
  	  if (secondary_mac != NULL)
 	    memcpy(eth_hdr->ether_dhost, secondary_mac, ETHER_ADDR_LEN);
 
-	  write_status = libnet_write_link_layer((struct libnet_link_int *)user, 
+	  write_status = libnet_write_link_layer((struct libnet_link_int *)write_if2, 
 						 interface2, data, pcap_hdr->caplen);
 	}
       }
-      
+     
+      else if (cidr_mode == 1) {
+        /* put the source ip of the packet into src_ip in x.x.x.x format */
+        ip_hdr = (struct libnet_ip_hdr *) (data + LIBNET_ETH_H);
+	/* drop martians */
+	if (nomartians == 1) {
+	   switch ((ntohl(ip_hdr->ip_dst.s_addr) & 0xff000000) >> 24) {
+           case 0: case 127: case 255:
+              write_status=1;
+	      continue;
+           }
+        }
+        /* we are using a cidr match */
+        if (check_ip_CIDR(ip_hdr->ip_src.s_addr)) {
+#ifdef DEBUG
+          /* in debug mode we need to set this flag */  
+          cidr_match = 1;
+#endif
+          /*
+             To support routing packets through a device on either side
+             of the interfaces, we need to rewrite the dst MAC address
+             so that the router will pick them off the wire.
+          */
+          if (primary_mac != NULL)
+            memcpy(eth_hdr->ether_dhost, primary_mac, ETHER_ADDR_LEN);
+   
+          write_status = libnet_write_link_layer((struct libnet_link_int *)write_if,
+                                                 interface, data, pcap_hdr->caplen);
+        }
+
+        else {
+#ifdef DEBUG
+          cidr_match = 0;
+#endif
+          /* do the mac rewrite thingy */
+          if (secondary_mac != NULL)
+            memcpy(eth_hdr->ether_dhost, secondary_mac, ETHER_ADDR_LEN);
+ 
+          write_status = libnet_write_link_layer((struct libnet_link_int *)write_if2,
+                                                 interface2, data, pcap_hdr->caplen);  
+        }
+      }
+
       else { /* looks like we're using a cache file */
 	/* 
 	   test to see if we have a match by applying a mask to the current byte 
@@ -408,7 +467,7 @@
 	*/
  	if (cachedata->data[cache_byte] & (char)pow((long)2, (long)cache_bit) ) {
 #ifdef DEBUG
-	  cidr_match = 1;
+	  cache_match = 1;
 #endif
 	  /* do the mac rewrite thingy */
 	  if (primary_mac != NULL)
@@ -420,7 +479,7 @@
 	
 	else {
 #ifdef DEBUG
-	  cidr_match = 0;
+	  cache_match = 0;
 #endif
 	  /* do the mac rewrite thingy */
 	  if (secondary_mac != NULL)
@@ -456,20 +515,30 @@
 
       if (regex_match == 0) {
 	fprintf(stderr, "Regex:      No Match (%s)\n", regex);
-	fprintf(stderr, "Interface:  %s\n", interface);
+	fprintf(stderr, "Interface:  %s\n", interface2);
       } else if (regex_match == 1) {
 	fprintf(stderr, "Regex:      Match (%s)\n", regex);
-	fprintf(stderr, "Interface:  %s\n", interface2);
-      } else if (cidr_match == 1) {
-	fprintf(stderr, "CIDR: Match\n");
+	fprintf(stderr, "Interface:  %s\n", interface);
+      } else if (cache_match == 1) {
+	fprintf(stderr, "Cache: Match\n");
 	fprintf(stderr, "Byte/Bit: %d/%d -> primary\n", cache_byte, cache_bit);
-      } else if (cidr_match == 0) {
-	fprintf(stderr, "CIDR: No Match\n");
+      } else if (cache_match == 0) {
+	fprintf(stderr, "Cache: No Match\n");
 	fprintf(stderr, "Byte/Bit: %d/%d -> secondary\n", cache_byte, cache_bit);
-       } else {
+      } else if (cidr_match == 0) {
+        fprintf(stderr, "CIDR: No Match\n");
+        fprintf(stderr, "Interface:  %s\n", interface2);
+      } else if (cidr_match == 1) {
+        fprintf(stderr, "CIDR: Match\n");
+        fprintf(stderr, "Interface:  %s\n", interface);
+      } else {
 	fprintf(stderr, "No CIDR/Regex Match Attempted\n");
       }
-      
+
+      if (cidr_mode == 1) {
+        memset (src_ip, '\0', 16);
+        strncat (src_ip, libnet_host_lookup(ip_hdr->ip_src.s_addr, RESOLVE), 15);
+      }
       fprintf(stderr, "Source IP:  %s\n", src_ip);
       memcpy(mac, eth_hdr->ether_dhost, MAC_SIZE-1);
       fprintf(stderr, "Dest MAC:   %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
@@ -506,8 +575,6 @@
 {
   pcap_t * in_file;
   char * cache_file = NULL;
-  struct libnet_link_int * write_if;   // Primary interface -i
-  struct libnet_link_int * write_if2;  // Secondary interface -j
   float Mrate = 0;                     // 
   double starttime_local, startusec;
   char ebuf[EBUF_SIZE];                      // Error buffer
@@ -539,15 +606,16 @@
   }
 
 #ifdef DEBUG
-  while ((ch = getopt(argc, argv, "b:e:d:i:j:l:r:c:m:hR:I:J:")) != -1)
+  while ((ch = getopt(argc, argv, "nb:e:d:i:j:l:r:c:m:h:R:I:J:C:")) != -1)
 #else
-  while ((ch = getopt(argc, argv, "b:e:i:j:l:r:c:m:hR:I:J:")) != -1)
+  while ((ch = getopt(argc, argv, "nb:e:i:j:l:r:c:m:h:R:I:J:C:")) != -1)
 #endif
     switch(ch) {
     case 'b':
       start = atoi(optarg);
       break;
     case 'c':
+      cache_mode = 1;
       cache_file = optarg;
       cache_packets = read_cache(cache_file);
       break;
@@ -578,7 +646,11 @@
     case 'h':
       usage();
       break;
+    case 'n':
+      nomartians = 1;
+      break;
     case 'R':
+      regex_mode = 1;
       regex = optarg;
       if ((regex_error = regcomp(preg, regex, regex_flags))) {
 	if (regerror(regex_error, preg, ebuf, EBUF_SIZE) != -1) {
@@ -595,6 +667,12 @@
     case 'J':
       secondary_mac = mac2hex(optarg, "Secondary MAC");
       break;
+    case 'C':
+      cidr_mode = 1;
+      if (! parse_cidr(optarg)) {
+        usage();
+      }
+      break;
     default:
       usage();
     }
@@ -616,8 +694,8 @@
     exit (1);
   }
 
-  if (((regex == NULL) && (cache_file == NULL)) && (interface2 != NULL)) {
-    fprintf(stderr, "Needs regex/cache with secondary interface\n"); 
+  if (((regex == NULL) && (cache_file == NULL) && (cidrdata == NULL)) && (interface2 != NULL)) {
+    fprintf(stderr, "Needs regex/cache/cidr with secondary interface\n"); 
     exit (1);
   }
 
@@ -712,7 +790,7 @@
         exit (1);
       }
       if (pcap_dispatch(in_file, 0,(void *)&write_packet,
-			(u_char *) write_if) == -1) {
+			NULL) == -1) {
 	pcap_perror(in_file, argv[1]);
       }
       pcap_close(in_file);
