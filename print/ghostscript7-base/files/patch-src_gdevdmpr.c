--- src/gdevdmpr.c.orig	Tue May 13 20:43:37 1997
+++ src/gdevdmpr.c	Tue Apr  2 01:16:25 2002
@@ -846,7 +846,7 @@
     if (env) {
       strcpy(fname,env);
       strcat(fname,
-        gp_file_name_concat_string(env,strlen(env),fname,strlen(fnamebase)));
+        gp_file_name_concat_string(env,strlen(env)));
       strcat(fname,fnamebase);
       fp = fopen(fname,gp_fmode_rb);
     }
