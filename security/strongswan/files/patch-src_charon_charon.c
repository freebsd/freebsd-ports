--- src/charon/charon.c.orig	2019-01-12 00:15:48 UTC
+++ src/charon/charon.c
@@ -377,7 +377,7 @@ int main(int argc, char *argv[])
 				status = 0;
 				goto deinit;
 			case 'v':
-				printf("Linux strongSwan %s\n", VERSION);
+				printf("FreeBSD strongSwan %s\n", VERSION);
 				status = 0;
 				goto deinit;
 			case 'l':
