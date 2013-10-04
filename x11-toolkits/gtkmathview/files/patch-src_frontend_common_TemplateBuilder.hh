--- src/frontend/common/TemplateBuilder.hh.orig	2013-10-04 14:50:03.000000000 +0200
+++ src/frontend/common/TemplateBuilder.hh	2013-10-04 14:55:16.000000000 +0200
@@ -47,12 +47,12 @@
   SmartPtr<typename ElementBuilder::type>
   getElement(const typename Model::Element& el) const
   {
-    if (SmartPtr<typename ElementBuilder::type> elem = smart_cast<typename ElementBuilder::type>(linkerAssoc(el)))
+    if (SmartPtr<typename ElementBuilder::type> elem = smart_cast<typename ElementBuilder::type>(this->linkerAssoc(el)))
       return elem;
     else
       {
-	SmartPtr<typename ElementBuilder::type> elem = ElementBuilder::type::create(ElementBuilder::getContext(*this));
-	linkerAdd(el, elem);
+	elem = ElementBuilder::type::create(ElementBuilder::getContext(*this));
+	this->linkerAdd(el, elem);
 	return elem;
       }
   }
