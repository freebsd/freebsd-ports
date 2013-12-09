--- libs/gcugtk/spectrumdoc.cc.orig	2013-12-03 20:54:28.000000000 +0100
+++ libs/gcugtk/spectrumdoc.cc	2013-12-03 20:55:55.000000000 +0100
@@ -1478,7 +1478,7 @@
 			break;	// this should not occur, but a corrupted or bad file is always possible
 		s.getline (line, 300);
 		if (strstr (line, "##")) {
-			s.seekg (-strlen (line) -1, _S_cur);
+			s.seekg (-strlen (line) -1, s.cur);
 			if (read > npoints) {
 				g_warning (_("Found too many data!"));
 				// FIXME: throw an exception
