--- code/D3MFImporter.cpp.orig	2016-07-08 17:29:51 UTC
+++ code/D3MFImporter.cpp
@@ -227,7 +227,7 @@ private:
         aiVector3D vertex;
         vertex.x = ai_strtof(xmlReader->getAttributeValue(D3MF::XmlTag::x.c_str()), nullptr);
         vertex.y = ai_strtof(xmlReader->getAttributeValue(D3MF::XmlTag::y.c_str()), nullptr);
-        vertex.z = ai_strtof>(xmlReader->getAttributeValue(D3MF::XmlTag::z.c_str()), nullptr);
+        vertex.z = ai_strtof(xmlReader->getAttributeValue(D3MF::XmlTag::z.c_str()), nullptr);
 
         return vertex;
     }
