--- parserInternals.c.orig	2012-05-15 03:16:38.000000000 +0000
+++ parserInternals.c	2013-03-13 09:35:54.000000000 +0000
@@ -1761,6 +1761,8 @@
     ctxt->charset = XML_CHAR_ENCODING_UTF8;
     ctxt->catalogs = NULL;
     ctxt->nbentities = 0;
+    ctxt->sizeentities = 0;
+    ctxt->sizeentcopy = 0;
     ctxt->input_id = 1;
     xmlInitNodeInfoSeq(&ctxt->node_seq);
     return(0);
