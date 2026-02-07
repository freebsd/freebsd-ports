--- spectool_raw.c.orig	2014-01-12 19:59:05.000000000 +0100
+++ spectool_raw.c	2014-01-12 19:59:50.000000000 +0100
@@ -101,7 +101,7 @@ int main(int argc, char *argv[]) {
 
 		if (o == 'h') {
 			Usage();
-			return;
+			return 0;
 		} else if (o == 'b') {
 			bcastlisten = 1;
 		} else if (o == 'n') {
