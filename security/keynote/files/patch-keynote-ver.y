--- keynote-ver.y.orig	1999-10-11 22:34:29 UTC
+++ keynote-ver.y
@@ -48,7 +48,7 @@ program: expr
        | STRING              { if (kn_add_authorizer(sessid, $1) != 0)
 				 return keynote_errno;
                                free($1);
-                             }
+                             };
 
 expr: VSTRING EQ STRING      { int i = kn_add_action(sessid, $1, $3, 0);
 
@@ -63,7 +63,7 @@ expr: VSTRING EQ STRING      { int i = k
 				 return i;
 			       free($1);
 			       free($3);
-                             } expr 
+                             } expr ;
 %%
 void
 kverror(char *s)
