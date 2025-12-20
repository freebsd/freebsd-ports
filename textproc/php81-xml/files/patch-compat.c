--- compat.c.orig	2025-12-16 18:33:34 UTC
+++ compat.c
@@ -14,6 +14,10 @@
    +----------------------------------------------------------------------+
  */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #if defined(HAVE_LIBXML) && (defined(HAVE_XML) || defined(HAVE_XMLRPC)) && !defined(HAVE_LIBEXPAT)
 #include "expat_compat.h"
@@ -376,7 +380,7 @@ _get_entity(void *user, const xmlChar *name)
 			ret = xmlGetDocEntity(parser->parser->myDoc, name);
 
 		ZEND_DIAGNOSTIC_IGNORED_START("-Wdeprecated-declarations")
-		if (ret == NULL || (parser->parser->instate != XML_PARSER_ENTITY_VALUE && parser->parser->instate != XML_PARSER_ATTRIBUTE_VALUE)) {
+		if (ret == NULL || parser->parser->instate == XML_PARSER_CONTENT) {
 		ZEND_DIAGNOSTIC_IGNORED_END
 			if (ret == NULL || ret->etype == XML_INTERNAL_GENERAL_ENTITY || ret->etype == XML_INTERNAL_PARAMETER_ENTITY || ret->etype == XML_INTERNAL_PREDEFINED_ENTITY) {
 				/* Predefined entities will expand unless no cdata handler is present */
