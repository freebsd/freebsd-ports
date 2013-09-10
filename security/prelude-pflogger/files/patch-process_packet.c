--- src/process_packet.c.orig	2005-09-18 10:29:54.000000000 -0400
+++ src/process_packet.c	2013-08-16 14:36:28.000000000 -0400
@@ -43,10 +43,10 @@
 #include <net/if_pflog.h>
 #include <net/pfvar.h>
 #include <netdb.h>
+#include <net/bpf.h>
 #include <pcap.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#include <net/bpf.h>
 #include <errno.h>
 
 #include <libprelude/prelude.h>
@@ -494,12 +494,12 @@
 					    char *dir_str,
 					    char *buffer, size_t size)
 {
-	struct { char *name; int n; } ip_proto_table[] = CTL_IPPROTO_NAMES;
+	struct protoent *proto;
 	char *proto_name = "unknown";
 
-	if ( packet_info->ip_proto_type < sizeof (ip_proto_table) / sizeof (ip_proto_table[0]) &&
-	     ip_proto_table[packet_info->ip_proto_type].name )
-		proto_name = ip_proto_table[packet_info->ip_proto_type].name;
+	proto = getprotobynumber(packet_info->ip_proto_type);
+	if (proto != NULL)
+		proto_name = proto->p_name;
 
 	return snprintf(buffer, size,
 			"OpenBSD PF %s an %s %s packet %s -> %s on interface %s (TTL:%hhu)",
