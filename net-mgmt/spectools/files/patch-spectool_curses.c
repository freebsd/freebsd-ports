--- spectool_curses.c.orig	2014-01-12 20:01:13.000000000 +0100
+++ spectool_curses.c	2014-01-12 20:01:40.000000000 +0100
@@ -90,7 +90,7 @@ int main(int argc, char *argv[]) {
 
 		if (o == 'h') {
 			Usage();
-			return;
+			return 0;
 		} else if (o == 'n') {
 			neturl = strdup(optarg);
 			continue;
@@ -98,20 +98,20 @@ int main(int argc, char *argv[]) {
 			if (sscanf(optarg, "%d", &range) != 1) {
 				printf("Expected number for range, see listing for supported ranges\n");
 				Usage();
-				return;
+				return -1;
 			}
 			continue;
 		} else if (o == 'd') {
 			if (sscanf(optarg, "%d", &device) != 1) {
 				printf("Expected number for device, see listing for detected devices\n");
 				Usage();
-				return;
+				return -1;
 			}
 
 			if (device < 0 || device >= ndev) {
 				printf("Device number invalid, see listing for detected devices\n");
 				Usage();
-				return;
+				return -1;
 			}
 
 			continue;
