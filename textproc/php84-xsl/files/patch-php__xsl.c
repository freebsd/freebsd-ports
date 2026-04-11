--- php_xsl.c.orig	2026-04-11 12:14:52 UTC
+++ php_xsl.c
@@ -323,7 +323,6 @@ PHP_MSHUTDOWN_FUNCTION(xsl)
 	xsltUnregisterExtModuleFunction ((const xmlChar *) "function",
 				   (const xmlChar *) "http://php.net/xsl");
 	xsltSetGenericErrorFunc(NULL, NULL);
-	xsltCleanupGlobals();
 
 	return SUCCESS;
 }
