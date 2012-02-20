--- lib/intersect_classify_common_impl.hpp.orig	2011-12-06 12:41:50.000000000 +0100
+++ lib/intersect_classify_common_impl.hpp	2011-12-06 12:41:59.000000000 +0100
@@ -250,6 +250,7 @@
           std::cerr << "d = " << d << std::endl;
 #endif
           fc = d < 0 ? FACE_IN : FACE_OUT;
+			break;
         }
 	default:
           CARVE_FAIL("unhandled switch case -- should not happen");
