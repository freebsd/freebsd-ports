--- common/read_ply.cpp.orig	2013-02-22 09:51:55.000000000 +0100
+++ common/read_ply.cpp	2013-02-22 09:52:16.000000000 +0100
@@ -255,7 +255,7 @@
 carve::poly::Polyhedron *readFile(std::istream &in, const carve::math::Matrix &transform) {
   carve::input::Input inputs;
   if (!readFile<filetype_t>(in, inputs, transform)) {
-    return false;
+    return NULL;
   }
   for (std::list<carve::input::Data *>::const_iterator i = inputs.input.begin(); i != inputs.input.end(); ++i) {
     carve::poly::Polyhedron *poly = inputs.create<carve::poly::Polyhedron>(*i);
