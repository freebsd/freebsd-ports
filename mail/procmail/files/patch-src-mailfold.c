--- src/mailfold.c.orig	2001-09-11 08:58:34.000000000 +0400
+++ src/mailfold.c	2010-12-06 12:55:44.000000000 +0300
@@ -378,7 +378,8 @@
 	dfilled=mailread=0;
      else if(rhead)				/* only read in a new header */
       { memblk new;
-	dfilled=mailread=0;makeblock(&new,0);readdyn(&new,&dfilled,0);
+	dfilled=mailread=0;makeblock(&new,0);
+	readdyn(&new,&dfilled,thebody-themail.p);
 	if(tobesent>dfilled&&isprivate)		     /* put it in place here */
 	 { tmemmove(themail.p+dfilled,thebody,filled-=tobesent);
 	   tmemmove(themail.p,new.p,dfilled);
