--- src/parse.c-	Tue Jul 16 02:38:21 2002
+++ src/parse.c	Tue Jul 16 02:38:36 2002
@@ -180,7 +180,7 @@
  if(!strcmp("POST",(*request_head)->method) ||
     !strcmp("PUT",(*request_head)->method))
    {
-    if(length==-1)
+    if(length<0)
       {free(url);return(NULL);}
 
     *request_body=CreateBody(length);
