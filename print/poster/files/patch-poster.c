--- poster.c.orig	1999-04-28 15:22:46 UTC
+++ poster.c
@@ -570,7 +570,7 @@ static int dsc_infile( double ps_bb[4])
 
 	got_bb = 0;
 	dsc_cont = inbody = gotall = level = atend = 0;
-	while (!gotall && (gets(buf) != NULL))
+	while (!gotall && (fgets(buf, BUFSIZE, stdin) != NULL))
 	{	
 		if (buf[0] != '%')
 		{	dsc_cont = 0;
