--- src/acc.c.orig	2004-04-11 11:43:55 UTC
+++ src/acc.c
@@ -147,6 +147,7 @@ static struct filter_chain *filterReadCo
 			if (strEq(fli->name, fi))
 			{
 				fc->filter = fli->filter;
+				fc->name = fli->name;
 				goto cont;
 			}
 		}
@@ -195,7 +196,7 @@ static struct filter_chain *filterReadCo
 					loge (("bad filter header/scope %s in file %s: %s", scope, fi, buf));
 					Exit(1);
 				}
-				*p='\0';
+				/* *p='\0'; */
 				f->scope = sc_header;
 				f->scope_header = Sstrdup(scope);
 			}
