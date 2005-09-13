--- src/acc.c.orig	Sat Feb 19 12:16:21 2000
+++ src/acc.c	Tue Sep 13 23:00:32 2005
@@ -195,7 +195,7 @@
 					loge (("bad filter header/scope %s in file %s: %s", scope, fi, buf));
 					Exit(1);
 				}
-				*p='\0';
+				/* *p='\0'; */
 				f->scope = sc_header;
 				f->scope_header = Sstrdup(scope);
 			}
