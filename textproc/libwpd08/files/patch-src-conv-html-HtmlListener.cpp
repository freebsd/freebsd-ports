--- src/conv/html/HtmlListenerImpl.cpp.orig	Tue Jun 28 00:31:29 2005
+++ src/conv/html/HtmlListenerImpl.cpp	Tue Jun 28 00:33:48 2005
@@ -144,7 +144,7 @@
 
 		printf("<span style=\"");
 		if (propList["style:font-name"])
-			printf("font-family: \'%s\'\;", propList["style:font-name"]->getStr().cstr());
+			printf("font-family: \'%s\';",propList["style:font-name"]->getStr().cstr());
 		if (propList["fo:font-size"])
 			printf("font-size: %s;", propList["fo:font-size"]->getStr().cstr());
 		if (propList["fo:font-weight"])
