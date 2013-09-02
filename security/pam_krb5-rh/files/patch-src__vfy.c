--- ./src/vfy.c.orig	2013-09-02 18:19:33.000000000 -0400
+++ ./src/vfy.c	2013-09-02 18:19:44.000000000 -0400
@@ -131,19 +131,6 @@
 			crit("error parsing AP-REQ: %s", v5_error_message(ret));
 			return ret;
 		}
-		if (ticket->enc_part2 != NULL) {
-			printf("transited: \"");
-			transited = ticket->enc_part2->transited.tr_contents;
-			for (i = 0; i < transited.length; i++) {
-				if (transited.data[i] > 32 &&
-			            transited.data[i] < 126) {
-					printf("%c", transited.data[i]);
-				} else {
-					printf("\%02x", transited.data[i]);
-				}
-			}
-			printf("\"\n");
-		}
 		printf("OK (%s)\n", argv[1]);
 	} else {
 		ret = krb5_build_principal_ext(ctx, &mcreds.server,
