--- src/matrix.cc.orig	Fri Oct 25 16:02:15 2002
+++ src/matrix.cc	Fri Oct 25 15:58:21 2002
@@ -166,14 +166,14 @@
 {
 	unsigned int i, j;
 
-	o << '/' << string (mat.rep->columns * 2, '-') << "-\\\n";
+	o << '/' << std::string (mat.rep->columns * 2, '-') << "-\\\n";
 	for (j = 0; j < mat.rep->rows; ++j) {
 		o << "| ";
 		for (i = 0; i < mat.rep->columns; ++i)
 			o << mat (i, j) << ' ';
 		o << "|\n";
 	}
-	o << '\\' << string (mat.rep->columns * 2, '-') << "-/\n";
+	o << '\\' << std::string (mat.rep->columns * 2, '-') << "-/\n";
 
 	return o;
 }
