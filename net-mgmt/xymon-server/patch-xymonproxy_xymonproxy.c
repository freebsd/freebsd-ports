--- xymonproxy/xymonproxy.c.orig	2015-02-17 17:31:01 UTC
+++ xymonproxy/xymonproxy.c
@@ -964,7 +964,7 @@ int main(int argc, char *argv[])
 		}
 
 		if (combining) {
-			selecttmo.tv_sec = 0; selecttmo.tv_usec = COMBO_DELAY;
+			selecttmo.tv_sec = 0; selecttmo.tv_usec = COMBO_DELAY / 1000;
 		}
 		else {
 			selecttmo.tv_sec = 1; selecttmo.tv_usec = 0;
