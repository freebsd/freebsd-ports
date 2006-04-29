--- ./src/globals.h.orig	Sun Apr  6 10:45:41 2003
+++ ./src/globals.h	Sat Apr 29 11:48:08 2006
@@ -342,6 +342,8 @@
   gchar *interface;		/* Network interface to listen to */
   gchar *filter;		/* Pcap filter to be used */
 
+  gboolean zero_delay;         /* no delay processing tcpdump files */
+
 }
 pref;
 
