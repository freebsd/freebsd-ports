--- physmain.c.orig	1998-08-30 12:48:34 UTC
+++ physmain.c
@@ -227,7 +227,7 @@ char const *s;
 				printf("Replace %s = ",v->name);
 				printexpr(v->value);
 				printf(" ?");
-				gets(answer);
+				fgets(answer, sizeof(answer), stdin);
 				printf("\n");
 			} else
 				answer[0] = 'Y';
@@ -656,7 +656,7 @@ void LegalCrap()
 
 }
 
-void main(argc, argv)
+int main(argc, argv)
 int argc;
 char *argv[];
 {	/* Main program: Init vars, load unit & help data, enter main loop */
@@ -711,7 +711,8 @@ char *argv[];
 	} else
 		while (TRUE) {
 			printf(">");
-			gets(buf);
+			if(fgets(buf, sizeof(buf), stdin) == NULL)
+				exit(0);
 			do_cmd(buf);
 		}
 }
