--- src/wsdlparser/WsdlParser.cpp.orig	Fri Mar 18 11:50:47 2005
+++ src/wsdlparser/WsdlParser.cpp	Fri Mar 18 11:52:37 2005
@@ -343,11 +343,11 @@
         string tag = xParser->getName();
         switch (event_type)
         {
-            case xParser->START_DOCUMENT:
+            case XmlPullParser::START_DOCUMENT:
                 if (m_State != START)
                     error("Syntax error at the start");
                 break;
-            case xParser->START_TAG:
+            case XmlPullParser::START_TAG:
                 if (xParser->getNamespace() != wsdlUri
                     &&xParser->getNamespace() != SchemaUri)
                     m_State = EXTENSIBILITY;
@@ -403,7 +403,7 @@
                 else
                     error("Unknown Tag " + tag);
                 break;
-            case xParser->END_TAG:
+            case XmlPullParser::END_TAG:
                 if (tag == "definitions")
                     m_State = END;
 
@@ -424,14 +424,14 @@
                         return peek(lookahead);   //get the next tag
                 }
                 break;
-            case xParser->TEXT:
-            case xParser->ENTITY_REF:
-            case xParser->COMMENT:
-            case xParser->PROCESSING_INSTRUCTION:
-            case xParser->CDSECT:
+            case XmlPullParser::TEXT:
+            case XmlPullParser::ENTITY_REF:
+            case XmlPullParser::COMMENT:
+            case XmlPullParser::PROCESSING_INSTRUCTION:
+            case XmlPullParser::CDSECT:
                 xParser->getText();
                 break;
-            case xParser->DOCDECL:
+            case XmlPullParser::DOCDECL:
                 error("Doc Declaration ??");
                 break;
             default:
