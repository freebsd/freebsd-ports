--- reader.c.orig	Sun May 12 00:57:41 2002
+++ reader.c	Sun May 12 01:00:39 2002
@@ -118,7 +118,7 @@
 static RTFStyle	*styleList = (RTFStyle *) NULL;
 
 
-static FILE	*rtffp = stdin;
+static FILE	*rtffp = NULL;
 
 
 /*
@@ -135,6 +135,7 @@
 RTFStyle	*sp;
 RTFStyleElt	*eltList, *ep;
 
+	rtffp = stdin;
 	/* initialize lookup table */
 	LookupInit ();
 
@@ -584,6 +585,8 @@
 {
 int	c;
 
+	if (rtffp == NULL)
+	  rtffp = stdin;
 	if ((c = getc (rtffp)) != EOF)
 	{
 		if (c & 0x80)
