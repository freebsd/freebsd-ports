--- src/matrix.h.orig	Thu Nov 28 05:36:37 2002
+++ src/matrix.h	Thu Nov 28 05:40:53 2002
@@ -24,12 +24,13 @@
 		~MatrixRep ();
 	};
 
-	MatrixRep *rep;
 
 	void unref ();
 	void mutator ();
 
 public:
+	MatrixRep *rep;
+
 	Matrix (unsigned int _rows, unsigned int _columns);
 	Matrix (const Matrix &other);
 	~Matrix ();
