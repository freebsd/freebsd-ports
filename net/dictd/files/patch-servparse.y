--- servparse.y~	Wed Nov 20 20:04:50 2002
+++ servparse.y	Wed Nov 20 20:04:59 2002
@@ -125,6 +125,7 @@
                ;
 
 Site : T_SITE T_STRING { $$ = $2; }
+     ;
 
 UserList : T_USERNAME T_STRING T_STRING
            { $$ = hsh_create(NULL,NULL);
