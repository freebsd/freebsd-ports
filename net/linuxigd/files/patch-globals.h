--- globals.h.orig	Mon Nov 13 01:14:11 2006
+++ globals.h	Sat Jun 16 19:53:23 2007
@@ -1,6 +1,7 @@
 #ifndef _GLOBALS_H_
 #define _GLOBALS_H_
 
+#include <sys/socket.h>
 #include <net/if.h>
 
 #define CHAIN_NAME_LEN 32
@@ -17,17 +18,15 @@
   char extInterfaceName[IFNAMSIZ]; // The name of the external interface, picked up from the
                                    // command line
   char intInterfaceName[IFNAMSIZ]; // The name of the internal interface, picked from command line
+  char extIpAddress[16];
+  char intIpAddress[16];
 
-  // All vars below are read from /etc/upnpd.conf in main.c
+  // All vars below are read from %%PREFIX%%/etc/upnpd.conf in main.c
   int debug;  // 1 - print debug messages to syslog
                // 0 - no debug messages
-  char iptables[PATH_LEN];  // The full name and path of the iptables executable, used in pmlist.c
+  char ipnat[PATH_LEN];  // The full name and path of the ipnat executable, used in pmlist.c
   char upstreamBitrate[BITRATE_LEN];  // The upstream bitrate reported by the daemon
   char downstreamBitrate[BITRATE_LEN]; // The downstream bitrate reported by the daemon
-  char forwardChainName[CHAIN_NAME_LEN];  // The name of the iptables chain to put FORWARD rules in
-  char preroutingChainName[CHAIN_NAME_LEN]; // The name of the chain to put PREROUTING rules in
-  int forwardRules;     // 1 - forward rules are inserted
-                          // 0 - no forward rules inserted
   long int duration;    // 0 - no duration
                           // >0 - duration in seconds
                           // <0 - expiration time 
@@ -38,14 +37,12 @@
 typedef struct GLOBALS* globals_p;
 extern struct GLOBALS g_vars;
 
-#define CONF_FILE "/etc/upnpd.conf"
+#define CONF_FILE "%%PREFIX%%/etc/upnpd.conf"
 #define MAX_CONFIG_LINE 256
-#define IPTABLES_DEFAULT_FORWARD_CHAIN "FORWARD"
-#define IPTABLES_DEFAULT_PREROUTING_CHAIN "PREROUTING"
 #define DEFAULT_DURATION 0
 #define DEFAULT_UPSTREAM_BITRATE "0"
 #define DEFAULT_DOWNSTREAM_BITRATE "0"
 #define DESC_DOC_DEFAULT "gatedesc.xml"
-#define XML_PATH_DEFAULT "/etc/linuxigd"
+#define XML_PATH_DEFAULT "%%PREFIX%%/etc/linuxigd"
 
 #endif // _GLOBALS_H_
