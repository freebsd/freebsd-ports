--- src/schemaparser/TypeContainer.h.orig	Fri Dec 22 19:15:37 2006
+++ src/schemaparser/TypeContainer.h	Fri Dec 22 19:16:01 2006
@@ -45,7 +45,7 @@
 {
  public:
   TypeContainer(int  typeId,const SchemaParser * sp);
-  TypeContainer::TypeContainer(ContentModel* cm,
+  TypeContainer(ContentModel* cm,
 			       const SchemaParser * sp);
   ~TypeContainer();
   TypeContainer *getAttributeContainer(std::string attName, 
