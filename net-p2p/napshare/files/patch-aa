--- src/hosts.c.orig	Sat Jan  4 13:25:05 2003
+++ src/hosts.c	Sat Jan  4 13:27:43 2003
@@ -265,6 +265,11 @@
 			g_snprintf(h_tmp, sizeof(h_tmp), "%s/NAPS-urlcache.txt", path);
 			cachef = fopen(h_tmp, "r"); // open the normal file
 			}
+		// Try opening from data directory
+		if (cachef == NULL) {
+			g_snprintf(h_tmp, sizeof(h_tmp), "%s/NAPS-urlcache.txt", PACKAGE_DATA_DIR);
+			cachef = fopen(h_tmp, "r");
+		}
 		}
 
 	if (!cachef) {
