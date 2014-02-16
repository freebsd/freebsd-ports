--- src/bin/geom/geom.cc.orig
+++ src/bin/geom/geom.cc
@@ -115,6 +115,7 @@
 void fill_sym_matrix(double **A, int size);
 }} // namespace psi::geom
 
+int
 main(int argc, char* argv[])
 {
   using namespace psi::geom;
