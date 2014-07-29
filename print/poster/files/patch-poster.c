--- poster.c.org	Thu Apr 29 00:22:46 1999
+++ poster.c	Sun Jan 30 00:48:11 2000
@@ -570,7 +570,7 @@
 
 	got_bb = 0;
 	dsc_cont = inbody = gotall = level = atend = 0;
-	while (!gotall && (gets(buf) != NULL))
+	while (!gotall && (fgets(buf, BUFSIZE, stdin) != NULL))
 	{	
 		if (buf[0] != '%')
 		{	dsc_cont = 0;
