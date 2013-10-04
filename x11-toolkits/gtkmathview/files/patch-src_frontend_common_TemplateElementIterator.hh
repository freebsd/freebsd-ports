--- src/frontend/common/TemplateElementIterator.hh.orig	2013-10-04 14:59:19.000000000 +0200
+++ src/frontend/common/TemplateElementIterator.hh	2013-10-04 14:59:40.000000000 +0200
@@ -43,7 +43,7 @@
   findValidNodeForward(const typename Model::Node& p0) const
   {
     for (typename Model::Node p = p0; p; p = Model::getNextSibling(p))
-      if (valid(p)) return Model::asElement(p);
+      if (this->valid(p)) return Model::asElement(p);
     return typename Model::Element();
   }
     
