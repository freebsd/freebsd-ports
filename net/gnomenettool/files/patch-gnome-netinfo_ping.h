--- gnome-netinfo/ping.h.orig	Sat Dec  6 23:11:01 2003
+++ gnome-netinfo/ping.h	Sat Dec  6 23:17:53 2003
@@ -25,7 +25,7 @@
 
 /* The ping usage and output is different between Unix flavours */
 /* FIXME: Add BSD support */
-#if defined(__linux__) || defined(__OSF__)
+#if defined(__linux__) || defined(__OSF__) || defined(__FreeBSD__)
 #   define PING_PROGRAM_FORMAT "%s ping -c %d -n %s"
 #   define PING_PROGRAM_FORMAT_6 "%s ping6 -c %d -n %s"
 #   define PING_FORMAT "%d bytes from %s icmp_seq=%d ttl=%d time=%s %s"
