diff -u -r8.359.2.8 parseaddr.c
--- sendmail/parseaddr.c	3 Apr 2003 16:20:54 -0000	8.359.2.8
+++ sendmail/parseaddr.c	16 Sep 2003 18:06:22 -0000
@@ -700,7 +700,11 @@
 						addr[MAXNAME] = '\0';
 	returnnull:
 					if (delimptr != NULL)
+					{
+						if (p > addr)
+							--p;
 						*delimptr = p;
+					}
 					CurEnv->e_to = saveto;
 					return NULL;
 				}
