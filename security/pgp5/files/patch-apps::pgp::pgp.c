--- apps/pgp/pgp.c.orig	Wed Nov 21 16:48:19 2001
+++ apps/pgp/pgp.c	Wed Nov 21 16:48:00 2001
@@ -1095,6 +1095,7 @@
 				break;
 					
 			case 'p':
+			case '5':
 				invoked_type = PGPraw;
 				break;
 					
