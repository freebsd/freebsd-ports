--- ./srclib/apr-util/xml/apr_xml.c.orig	2007-04-02 12:19:29.000000000 -0400
+++ ./srclib/apr-util/xml/apr_xml.c	2010-05-06 16:06:03.712831964 -0400
@@ -339,6 +339,25 @@
     return APR_SUCCESS;
 }
 
+#if XML_MAJOR_VERSION > 1
+/* Stop the parser if an entity declaration is hit. */
+static void entity_declaration(void *userData, const XML_Char *entityName,
+                               int is_parameter_entity, const XML_Char *value,
+                               int value_length, const XML_Char *base,
+                               const XML_Char *systemId, const XML_Char *publicId,
+                               const XML_Char *notationName)
+{
+    apr_xml_parser *parser = userData;
+
+    XML_StopParser(parser->xp, XML_FALSE);
+}
+#else
+/* A noop default_handler. */
+static void default_handler(void *userData, const XML_Char *s, int len)
+{
+}
+#endif
+
 APU_DECLARE(apr_xml_parser *) apr_xml_parser_create(apr_pool_t *pool)
 {
     apr_xml_parser *parser = apr_pcalloc(pool, sizeof(*parser));
@@ -364,6 +383,19 @@
     XML_SetElementHandler(parser->xp, start_handler, end_handler);
     XML_SetCharacterDataHandler(parser->xp, cdata_handler);
 
+    /* Prevent the "billion laughs" attack against expat by disabling
+     * internal entity expansion.  With 2.x, forcibly stop the parser
+     * if an entity is declared - this is safer and a more obvious
+     * failure mode.  With older versions, installing a noop
+     * DefaultHandler means that internal entities will be expanded as
+     * the empty string, which is also sufficient to prevent the
+     * attack. */
+#if XML_MAJOR_VERSION > 1
+    XML_SetEntityDeclHandler(parser->xp, entity_declaration);
+#else
+    XML_SetDefaultHandler(parser->xp, default_handler);
+#endif
+
     return parser;
 }
 
