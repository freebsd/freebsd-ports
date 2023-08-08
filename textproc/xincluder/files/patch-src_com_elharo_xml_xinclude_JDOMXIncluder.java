--- src/com/elharo/xml/xinclude/JDOMXIncluder.java.orig	2003-03-09 16:01:34 UTC
+++ src/com/elharo/xml/xinclude/JDOMXIncluder.java
@@ -54,6 +54,7 @@ import org.jdom.CDATA;
 import org.jdom.Namespace;
 import org.jdom.Comment;
 import org.jdom.CDATA;
+import org.jdom.DocType;
 import org.jdom.Text;
 import org.jdom.JDOMException;
 import org.jdom.Attribute;
@@ -404,6 +405,13 @@ public class JDOMXIncluder {
                 // I need to return the full document child list including comments and PIs, 
                 // not just the resolved root
                 List topLevelNodes = doc.getContent();
+                for (int i = 0; i < topLevelNodes.size(); i++) {
+                    Object o = topLevelNodes.get(i);
+                    if (o instanceof DocType) {
+                      DocType docType = (DocType) o;
+                      docType.detach();     
+                    } 
+                }
                 int rootPosition = topLevelNodes.indexOf(root);
                 List beforeRoot = topLevelNodes.subList(0, rootPosition);
                 List afterRoot = topLevelNodes.subList(rootPosition+1, topLevelNodes.size());
