--- src/parser.c.orig	2018-10-06 12:48:05 UTC
+++ src/parser.c
@@ -2322,7 +2322,7 @@ int SigSuppressAddElement(SigSuppress_li
 	{
 	    memset(&comp_set,'\0',(sizeof(u_int8_t)*4));
 	    
-	    if( (cNode->gid == sElement->gid))
+	    if (cNode->gid == sElement->gid)
 	    {
 		switch(sElement->ss_type)
 		{
