--- keynote-ver-orig.y	Tue Oct 12 00:34:29 1999
+++ keynote-ver.y	Wed May 28 14:47:32 2003
@@ -48,7 +48,7 @@
        | STRING              { if (kn_add_authorizer(sessid, $1) != 0)
 				 return keynote_errno;
                                free($1);
-                             }
+                             };
 
 expr: VSTRING EQ STRING      { int i = kn_add_action(sessid, $1, $3, 0);
 
@@ -63,7 +63,7 @@
 				 return i;
 			       free($1);
 			       free($3);
-                             } expr 
+                             } expr ;
 %%
 void
 kverror(char *s)
