--- src/lib/StarObjectSmallGraphic.cxx.orig	2018-04-25 11:44:09 UTC
+++ src/lib/StarObjectSmallGraphic.cxx
@@ -1389,7 +1389,7 @@ bool SdrGraphicPath::send(STOFFListenerPtr &listener, 
   else {
     shape.m_command=STOFFGraphicShape::C_Path;
     librevenge::RVNGPropertyListVector path;
-    for (auto const poly : m_pathPolygons)
+    for (auto const &poly : m_pathPolygons)
       poly.addToPath(path, isClosed, state.m_global->m_relativeUnit, state.m_global->m_offset);
     shape.m_propertyList.insert("svg:d", path);
   }
@@ -1402,7 +1402,7 @@ bool SdrGraphicPath::send(STOFFListenerPtr &listener, 
 
 ////////////////////////////////////////
 //! Internal: virtual class to store a Sdr graphic uno
-class SdrGraphicUno : public SdrGraphicRect
+class SdrGraphicUno final : public SdrGraphicRect
 {
 public:
   //! constructor
