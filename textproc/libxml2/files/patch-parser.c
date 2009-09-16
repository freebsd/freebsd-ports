--- parser.c.orig	2009-09-16 17:00:06.000000000 +0200
+++ parser.c	2009-09-16 17:01:07.000000000 +0200
@@ -10130,8 +10130,12 @@ xmlParseDocument(xmlParserCtxtPtr ctxt) 
     /*
      * Check for the XMLDecl in the Prolog.
      * do not GROW here to avoid the detected encoder to decode more
-     * than just the first line
+     * than just the first line, unless the amount of data is really
+     * too small to hold "<?xml version="1.0" encoding="foo"
      */
+    if ((ctxt->input->end - ctxt->input->cur) < 35) {
+       GROW;
+    }
     if ((CMP5(CUR_PTR, '<', '?', 'x', 'm', 'l')) && (IS_BLANK_CH(NXT(5)))) {
 
 	/*
