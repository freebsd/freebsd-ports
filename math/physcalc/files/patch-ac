--- physmain.c.orig	1998-08-30 14:48:34.000000000 -0500
+++ physmain.c	2009-06-25 22:32:46.000000000 -0500
@@ -227,7 +227,7 @@
 				printf("Replace %s = ",v->name);
 				printexpr(v->value);
 				printf(" ?");
-				gets(answer);
+				fgets(answer, sizeof(answer), stdin);
 				printf("\n");
 			} else
 				answer[0] = 'Y';
@@ -711,7 +711,8 @@
 	} else
 		while (TRUE) {
 			printf(">");
-			gets(buf);
+			if(fgets(buf, sizeof(buf), stdin) == NULL)
+				exit(0);
 			do_cmd(buf);
 		}
 }
