--- net.c.orig	2007-11-08 13:24:24.000000000 +0000
+++ net.c	2007-11-08 13:27:30.000000000 +0000
@@ -150,10 +150,10 @@
     {
 		if (parms.no_false_200_search == FALSE)
 		{
-			if (strnstr(httpbuff, "file not found") ||
-				strnstr(httpbuff, "error 404") ||
-				strnstr(httpbuff, "document has moved") ||
-				strnstr(httpbuff, "page you have requested") ) // Wise?
+			if (cgichk_strnstr(httpbuff, "file not found") ||
+				cgichk_strnstr(httpbuff, "error 404") ||
+				cgichk_strnstr(httpbuff, "document has moved") ||
+				cgichk_strnstr(httpbuff, "page you have requested") ) // Wise?
 			{
 				err = HTTP_NOEXIST;
 			}
@@ -161,7 +161,7 @@
 			// If user spcified an additional string to search for, check for that too.
 			if (parms.alt_fake_404_string)
 			{
-				if (strnstr(httpbuff, parms.alt_fake_404_string))
+				if (cgichk_strnstr(httpbuff, parms.alt_fake_404_string))
 				{
 					err = HTTP_NOEXIST;
 				}
