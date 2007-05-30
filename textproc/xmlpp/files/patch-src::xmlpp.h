--- src/xmlpp.h.orig	Wed May 30 19:54:52 2007
+++ src/xmlpp.h	Wed May 30 19:55:11 2007
@@ -133,7 +133,7 @@
    XMLNode & operator =(const XMLNodePtr n);
 	
 	//! returns or sets the node name
-	string XMLNode::name(string _name="");
+	string name(string _name="");
   	//! returns or sets the type of the node	
 	xmlnodetype type(xmlnodetype ntype=xml_nt_dummy);
 	//! ireturns or sets cdata string
