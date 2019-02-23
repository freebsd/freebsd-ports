--- src/frontend/common/TemplateElementIterator.hh.orig	2007-08-17 10:02:34 UTC
+++ src/frontend/common/TemplateElementIterator.hh
@@ -43,7 +43,7 @@ class GMV_MathView_EXPORT TemplateElementIterator : pu
   findValidNodeForward(const typename Model::Node& p0) const
   {
     for (typename Model::Node p = p0; p; p = Model::getNextSibling(p))
-      if (valid(p)) return Model::asElement(p);
+      if (this->valid(p)) return Model::asElement(p);
     return typename Model::Element();
   }
     
