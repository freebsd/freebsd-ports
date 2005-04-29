--- src/actions/kz-actions.c.orig	Fri Apr 29 08:19:03 2005
+++ src/actions/kz-actions.c	Fri Apr 29 08:19:31 2005
@@ -893,9 +893,10 @@
 	
 	if(counts != 1)
 	{
+		gint st;
 		gchar **temp = g_alloca(sizeof(gchar*) * (counts + 1));
 		splited = g_strsplit(format , "%" , counts);
-		gint st = 0;
+		st = 0;
 
 		for(i = 0; i < counts-1; i++)
 		{
