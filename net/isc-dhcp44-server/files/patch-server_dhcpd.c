--- server/dhcpd.c.orig	2022-09-28 14:39:15 UTC
+++ server/dhcpd.c
@@ -492,6 +492,9 @@ main(int argc, char **argv) {
 			cftest = 1;
 			lftest = 1;
 			log_perror = -1;
+		} else if (!strcmp (argv [i], "-Q")) {
+			quiet = 0;
+			quiet_interface_discovery = 0;
 		} else if (!strcmp (argv [i], "-q")) {
 			quiet = 1;
 			quiet_interface_discovery = 1;
