--- src/libxml/tree_parser.cxx.orig	Thu Oct 23 08:30:38 2003
+++ src/libxml/tree_parser.cxx	Thu Oct 23 08:30:44 2003
@@ -62,7 +62,7 @@
 struct xml::tree_impl {
     tree_impl (void) : last_error_(const_default_error), warnings_(false), okay_(false) {
 	std::memset(&sax_, 0, sizeof(sax_));
-	initxmlDefaultSAXHandler(&sax_, 0);
+	xmlSAX2InitDefaultSAXHandler(&sax_, 0);
 
 	sax_.warning	= cb_tree_warning;
 	sax_.error	= cb_tree_error;
