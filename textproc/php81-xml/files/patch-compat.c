--- compat.c.orig	2025-07-01 21:17:52 UTC
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
@@ -375,7 +379,9 @@ _get_entity(void *user, const xmlChar *name)
 		if (ret == NULL)
 			ret = xmlGetDocEntity(parser->parser->myDoc, name);
 
-		if (ret == NULL || (parser->parser->instate != XML_PARSER_ENTITY_VALUE && parser->parser->instate != XML_PARSER_ATTRIBUTE_VALUE)) {
+/* Fix parse error on some XML files so that devel/pear work again. */
+/* See https://github.com/php/php-src/issues/14834 for details. */
+		if (ret == NULL || parser->parser->instate == XML_PARSER_CONTENT) {
 			if (ret == NULL || ret->etype == XML_INTERNAL_GENERAL_ENTITY || ret->etype == XML_INTERNAL_PARAMETER_ENTITY || ret->etype == XML_INTERNAL_PREDEFINED_ENTITY) {
 				/* Predefined entities will expand unless no cdata handler is present */
 				if (parser->h_default && ! (ret && ret->etype == XML_INTERNAL_PREDEFINED_ENTITY && parser->h_cdata)) {
