--- src/config.h.orig	Mon Dec 13 12:26:43 2004
+++ src/config.h	Mon Dec 13 12:29:18 2004
@@ -39,7 +39,7 @@
  * GNU/Linux and some other (newer) systems might have this, its ok to say no
  * even if you dont have this, you just wont have the -- options on the command line
  */
-#define WITH_LONGOPTS
+//#define WITH_LONGOPTS
 
 /*
  * lots of newer bsd'ish systems have this as well as some (newer?) linux systems. youll need this
@@ -47,7 +47,7 @@
  * and are not running linux, however it likely will not work arp scanning.
  * side note: dont use this on linux, its broken!
  */
-/* #define WITH_IFADDRS */
+#define WITH_IFADDRS 
 
 /*
  * XXX
@@ -56,13 +56,13 @@
  * (HINT: define both of none of WITH_IFADDRS and WITH_IF_DL, if you only define one, expect serious compile errors)
  * if you have solaris, then you need this, and pray things work out for you.
  */
-/* #define WITH_IF_DL */
+#define WITH_IF_DL
 
 /*
  * bsd'ish boxes with bpf stuff included with the system, otherwise dont use it.
  * linux people dont need this really even if they think they have this
  */
-/*#define HAVE_BPF_H */
+#define HAVE_BPF_H 
 
 /*
  * most people these days have this file, if you _dont_ have it, then youll need to put the "full path"
@@ -80,7 +80,7 @@
  * with linux, define this (or if you have /proc/net/route)
  * otherwise use we will make due, remeber to use -i if you dont have /proc/net/route
  */
-#define HAVE_PROC_NET_ROUTE
+/* #define HAVE_PROC_NET_ROUTE */
 /*
  * XXX
  * you shouldnt have to play with these, most likely
@@ -128,8 +128,8 @@
 
 #define MODULE_DIR	PREFIX "/libexec/" TARGETNAME "/modules"
 #define PORT_NUMBERS	PREFIX "/share/" TARGETNAME "/port-numbers"
-#define CONF_FILE	PREFIX "/share/" TARGETNAME "/unicorn.conf"
-#define OUI_CONF	PREFIX "/share/" TARGETNAME "/oui.conf"
+#define CONF_FILE	PREFIX "/etc/" TARGETNAME "/unicorn.conf"
+#define OUI_CONF	PREFIX "/etc/" TARGETNAME "/oui.conf"
 #define SENDER_PATH	PREFIX "/libexec/" TARGETNAME "/" SENDERNAME
 #define LISTENER_PATH	PREFIX "/libexec/" TARGETNAME "/" LISTENERNAME
 
