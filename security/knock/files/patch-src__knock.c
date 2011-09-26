--- ./src/knock.c.orig	2005-06-27 07:11:34.000000000 +0200
+++ ./src/knock.c	2011-08-17 13:21:28.000000000 +0200
@@ -1,8 +1,8 @@
 /*
  *  knock.c
- * 
+ *
  *  Copyright (c) 2004-2005 by Judd Vinet <jvinet@zeroflux.org>
- * 
+ *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 2 of the License, or
@@ -15,7 +15,7 @@
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program; if not, write to the Free Software
- *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, 
+ *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
  *  USA.
  */
 
@@ -23,16 +23,20 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <netdb.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#if defined(__FreeBSD__) || defined(__APPLE__)
+#include <netinet/in.h>
+#endif
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <string.h>
+#include <netinet/in.h>
 #include <resolv.h>
 #include <getopt.h>
 #include <fcntl.h>
 
-static char version[] = "0.5";
+static char version[] = "#VERSION#";
 
 #define PROTO_TCP 1
 #define PROTO_UDP 2
@@ -44,6 +48,7 @@
 
 int o_verbose = 0;
 int o_udp     = 0;
+int o_delay   = 0;
 
 int main(int argc, char** argv)
 {
@@ -55,12 +60,13 @@
 	{
 		{"verbose",   no_argument,       0, 'v'},
 		{"udp",       no_argument,       0, 'u'},
+		{"delay",     required_argument, 0, 'd'},
 		{"help",      no_argument,       0, 'h'},
 		{"version",   no_argument,       0, 'V'},
 		{0, 0, 0, 0}
 	};
 
-	while((opt = getopt_long(argc, argv, "vuhV", opts, &optidx))) {
+	while((opt = getopt_long(argc, argv, "vud:hV", opts, &optidx))) {
 		if(opt < 0) {
 			break;
 		}
@@ -68,6 +74,7 @@
 			case 0:   break;
 			case 'v': o_verbose = 1; break;
 			case 'u': o_udp = 1; break;
+			case 'd': o_delay = (int)atoi(optarg); break;
 			case 'V': ver();
 			case 'h': /* fallthrough */
 			default: usage();
@@ -77,6 +84,11 @@
 		usage();
 	}
 
+	if(o_delay < 0) {
+		fprintf(stderr, "error: delay cannot be negative\n");
+		exit(1);
+	}
+
 	host = gethostbyname(argv[optind++]);
 	if(host == NULL) {
 		fprintf(stderr, "Cannot resolve hostname\n");
@@ -98,16 +110,16 @@
 		} else {
 			port = atoi(arg);
 		}
-		
+
 		if(o_udp || proto == PROTO_UDP) {
-			sd = socket(PF_INET, SOCK_DGRAM, 0); 
+			sd = socket(PF_INET, SOCK_DGRAM, 0);
 			if(sd == -1) {
 				fprintf(stderr, "Cannot open socket\n");
 				exit(1);
 			}
 		} else {
 			int flags;
-			sd = socket(PF_INET, SOCK_STREAM, 0); 
+			sd = socket(PF_INET, SOCK_STREAM, 0);
 			if(sd == -1) {
 				fprintf(stderr, "Cannot open socket\n");
 				exit(1);
@@ -121,13 +133,13 @@
 		addr.sin_port = htons(port);
 		if(o_udp || proto == PROTO_UDP) {
 			vprint("hitting udp %s:%u\n", inet_ntoa(addr.sin_addr), port);
-			connect(sd, (struct sockaddr*)&addr, sizeof(struct sockaddr));
-			send(sd, NULL, 0, MSG_DONTWAIT);
+			sendto(sd, "", 1, 0, (struct sockaddr*)&addr, sizeof(addr));
 		} else {
 			vprint("hitting tcp %s:%u\n", inet_ntoa(addr.sin_addr), port);
 			connect(sd, (struct sockaddr*)&addr, sizeof(struct sockaddr));
 		}
 		close(sd);
+		usleep(1000*o_delay);
 	}
 
 	return(0);
@@ -148,6 +160,7 @@
 	printf("usage: knock [options] <host> <port[:proto]> [port[:proto]] ...\n");
 	printf("options:\n");
 	printf("  -u, --udp            make all ports hits use UDP (default is TCP)\n");
+	printf("  -d, --delay <t>      wait <t> milliseconds between port hits\n");
 	printf("  -v, --verbose        be verbose\n");
 	printf("  -V, --version        display version\n");
 	printf("  -h, --help           this help\n");
