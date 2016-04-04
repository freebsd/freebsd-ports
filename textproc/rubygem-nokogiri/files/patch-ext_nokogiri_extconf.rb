--- ext/nokogiri/extconf.rb.orig	2016-04-02 21:13:17 UTC
+++ ext/nokogiri/extconf.rb
@@ -587,6 +587,43 @@ if ENV['CPUPROFILE']
   end
 end
 
+$INSTALLFILES = [
+  ['html_document.h', '$(archdir)'],
+  ['html_element_description.h', '$(archdir)'],
+  ['html_entity_lookup.h', '$(archdir)'],
+  ['html_sax_parser_context.h', '$(archdir)'],
+  ['html_sax_push_parser.h', '$(archdir)'],
+  ['nokogiri.h', '$(archdir)'],
+  ['xml_attr.h', '$(archdir)'],
+  ['xml_attribute_decl.h', '$(archdir)'],
+  ['xml_cdata.h', '$(archdir)'],
+  ['xml_comment.h', '$(archdir)'],
+  ['xml_document.h', '$(archdir)'],
+  ['xml_document_fragment.h', '$(archdir)'],
+  ['xml_dtd.h', '$(archdir)'],
+  ['xml_element_content.h', '$(archdir)'],
+  ['xml_element_decl.h', '$(archdir)'],
+  ['xml_encoding_handler.h', '$(archdir)'],
+  ['xml_entity_decl.h', '$(archdir)'],
+  ['xml_entity_reference.h', '$(archdir)'],
+  ['xml_io.h', '$(archdir)'],
+  ['xml_libxml2_hacks.h', '$(archdir)'],
+  ['xml_namespace.h', '$(archdir)'],
+  ['xml_node.h', '$(archdir)'],
+  ['xml_node_set.h', '$(archdir)'],
+  ['xml_processing_instruction.h', '$(archdir)'],
+  ['xml_reader.h', '$(archdir)'],
+  ['xml_relax_ng.h', '$(archdir)'],
+  ['xml_sax_parser.h', '$(archdir)'],
+  ['xml_sax_parser_context.h', '$(archdir)'],
+  ['xml_sax_push_parser.h', '$(archdir)'],
+  ['xml_schema.h', '$(archdir)'],
+  ['xml_syntax_error.h', '$(archdir)'],
+  ['xml_text.h', '$(archdir)'],
+  ['xml_xpath_context.h', '$(archdir)'],
+  ['xslt_stylesheet.h', '$(archdir)'],
+]
+
 create_makefile('nokogiri/nokogiri')
 
 if enable_config('clean', true)
