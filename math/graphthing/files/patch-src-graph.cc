--- src/graph.cc.orig	Tue Feb 12 05:51:39 2002
+++ src/graph.cc	Fri Oct 25 17:16:21 2002
@@ -82,8 +82,14 @@
 	}
 
 	/* We don't want anything skipped */
-	fs.setf (0);
-
+#if __FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version >= 500035
+	fs.setf(std::ios_base::fmtflags(0));
+#else
+	fs.setf(0);
+#endif
+#endif
 	new_graph = new Graph ();
 	yy_gt_fs = &fs;
 	success = (yy_gt_parse () == 0);
@@ -105,7 +111,7 @@
 	fs.open (fname, std::fstream::out);
 	if (!fs.is_open ()) {
 		/* std::cerr << "*** Couldn't open \"" << fname << "\"\n"; */
-		throw runtime_error ("Couldn't open file.");
+		throw std::runtime_error ("Couldn't open file.");
 	}
 
 	fs << *this;
@@ -128,7 +134,7 @@
 	fs.open (fname, std::fstream::out);
 	if (!fs.is_open ()) {
 		/* std::cerr << "*** Couldn't open \"" << fname << "\"\n"; */
-		throw runtime_error ("Couldn't open file.");
+		throw std::runtime_error ("Couldn't open file.");
 	}
 
 	minx = miny = 999999;
