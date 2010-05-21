--- src/licq-osd.cpp.orig	Tue Aug 17 20:02:35 2004
+++ src/licq-osd.cpp	Mon Mar  7 18:42:53 2005
@@ -804,7 +804,7 @@
 
     while ((fromsize>0) && (tosize>0))
     {
-	if ((int)iconv(conv, (char **)&msgptr, &fromsize, &resptr, &tosize)==-1)
+	if ((int)iconv(conv, (const char**)(&msgptr), &fromsize, &resptr, &tosize)==-1)
 	{
 	    // array is not enough
 	    if (errno == E2BIG)
