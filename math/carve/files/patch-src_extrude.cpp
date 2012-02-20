--- src/extrude.cpp.orig	2011-12-01 11:57:16.000000000 +0100
+++ src/extrude.cpp	2011-12-01 11:59:06.000000000 +0100
@@ -31,6 +31,7 @@
 #include "write_ply.hpp"
 
 #include <iostream>
+#include <stdexcept>
 
 template<unsigned ndim>
 carve::geom::vector<ndim> lerp(
