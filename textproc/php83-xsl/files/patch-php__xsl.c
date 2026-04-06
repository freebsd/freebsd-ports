--- php_xsl.c.orig	2026-04-04 20:11:31 UTC
+++ php_xsl.c
@@ -212,7 +212,6 @@ PHP_MSHUTDOWN_FUNCTION(xsl)
 	xsltUnregisterExtModuleFunction ((const xmlChar *) "function",
 				   (const xmlChar *) "http://php.net/xsl");
 	xsltSetGenericErrorFunc(NULL, NULL);
-	xsltCleanupGlobals();
 
 	return SUCCESS;
 }
