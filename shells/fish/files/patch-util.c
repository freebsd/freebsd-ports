
--- util.c.orig	2010-01-13 06:44:46.000000000 -0800
+++ util.c	2010-01-13 06:46:39.000000000 -0800
@@ -320,7 +320,7 @@
 {
 	int pos;
 	
-	if( (float)(h->count+1)/h->size > 0.75f )
+	if( (float)(h->count+1) > 0.75f * h->size )
 	{
 		if( !hash_realloc( h, (h->size+1) * 2 -1 ) )
 		{


