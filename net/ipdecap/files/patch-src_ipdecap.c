--- src/ipdecap.c.orig	2018-07-19 13:30:02 UTC
+++ src/ipdecap.c
@@ -20,6 +20,7 @@
 
 #include <err.h>           // for warnx
 #include <getopt.h>        // for getopt_long, optarg, required_argument
+#include <sys/types.h>     // for u_char, u_int16_t
 #include <net/ethernet.h>  // for ether_header, ether_addr, ETHERTYPE_IP
 #include <netinet/in.h>    // for ntohs, htons, IPPROTO_ESP, IPPROTO_GRE
 #include <netinet/ip.h>    // for ip
@@ -31,7 +32,6 @@
 #include <stdio.h>         // for NULL, printf
 #include <stdlib.h>        // for free, exit, EXIT_FAILURE, EXIT_SUCCESS
 #include <string.h>        // for memcpy, memset, strcmp
-#include <sys/types.h>     // for u_char, u_int16_t
 #include "esp.h"           // for flows_cleanup, parse_esp_conf, print_algor...
 #include "gre.h"           // for grehdr, GRE_CHECKSUM, GRE_KEY, GRE_ROUTING
 #include "config.h"
