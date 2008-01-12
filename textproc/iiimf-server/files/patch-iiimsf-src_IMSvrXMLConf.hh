--- iiimsf/src/IMSvrXMLConf.hh.orig	2007-12-21 19:19:48.000000000 +0100
+++ iiimsf/src/IMSvrXMLConf.hh	2007-12-21 19:20:00.000000000 +0100
@@ -14,7 +14,7 @@
 
     IMAuth::access_type get_access_type(xmlChar *key);
 
-    string IMSvrXMLConf::parse_text_node(xmlNodePtr &node);
+    string parse_text_node(xmlNodePtr &node);
     string parse_hostname_node(xmlNodePtr &node);
     string parse_port_node(xmlNodePtr &node);
     string parse_file_node(xmlNodePtr &node);
