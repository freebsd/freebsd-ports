--- dclib/core/cxml.cpp.orig	Thu Aug 12 10:32:06 2004
+++ dclib/core/cxml.cpp	Wed Dec  1 23:14:00 2004
@@ -149,10 +149,8 @@
 		printf("UTF8Toisolat1 transcoding fail: '%s'\n",s);
 	else if ( res == -1 )
 		printf("UTF8Toisolat1 fail: '%s'\n",s);
-	else if ( res == 0 )
-		r = (char*)b;
 	else
-		printf("CXml::xml_UTF8Toisolat1 error %d\n",res);
+		r = (char*)b;
 
 	free(b);
 
@@ -180,7 +178,7 @@
 
 	if ( res == -1 )
 		printf("isolat1ToUTF8 fail: '%s'\n",s);
-	else if ( res == 0 )
+	else
 		r = (char*)b;
 
 	free(b);
