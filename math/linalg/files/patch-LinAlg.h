--- LinAlg.h.orig	Fri Oct  8 11:30:11 2004
+++ LinAlg.h	Fri Oct  8 11:43:29 2004
@@ -393,8 +393,8 @@
 				// with 2^n columns
 class haar_matrix : public LazyMatrix
 {
-  void fill_in(Matrix& m) const;
 public:
+  void fill_in(Matrix& m) const;
   haar_matrix(const int n, const int no_cols=0);
 };
 
@@ -505,7 +505,9 @@
   {
     friend class Reference;
     Matrix& m;
+#if defined(__GNUC__) && (__GNUC__ < 3)
     ConstReference(const ConstReference&);	// Not implemented and forbidden
+#endif
     void operator = (const ConstReference&);	// reference isn't transferable
   public:
     ConstReference(const Matrix& _m)
@@ -831,7 +833,9 @@
   
   void operator=(const ElementWiseConst&);// is not implemented, ergo, is
                                         // not allowed
+#if defined(__GNUC__) && (__GNUC__ < 3)
   ElementWiseConst(const ElementWiseConst&);// Cloning is not allowed, either
+#endif
   
 				// A private constructor, to make
 				// sure the object can't be constructed
@@ -1231,7 +1235,9 @@
   friend class LAStreamOut;
   const REAL * const col_ptr;		// Pointer to the column under
   					// consideration
+#if defined(__GNUC__) && (__GNUC__ < 3)
   ConstMatrixColumn(const ConstMatrixColumn&);	// Not implemented and forbidden:
+#endif
   void operator = (const ConstMatrixColumn&);// no cloning/assignment allowed
 
 protected:
@@ -1267,7 +1273,9 @@
 {
   friend class ElementWise;
   friend class LAStreamOut;
+#if defined(__GNUC__) && (__GNUC__ < 3)
   MatrixColumn(const MatrixColumn&);	// Not implemented and forbidden:
+#endif
   void operator = (const MatrixColumn&);// no cloning/assignment allowed
 public:					// Take a col of the matrix
   MatrixColumn(Matrix& m, const int col) :
@@ -1295,7 +1303,9 @@
 					// col after col, stride = nrows
   const REAL * const end_ptr;		// Points after the end of the matrix
   
+#if defined(__GNUC__) && (__GNUC__ < 3)
   ConstMatrixRow(const ConstMatrixRow&);	// Not implemented and forbidden:
+#endif
   void operator = (const ConstMatrixRow&);	// no cloning/assignment allowed
 
 protected:
@@ -1336,7 +1346,9 @@
 {
   friend class ElementWiseStride;
   friend class LAStrideStreamOut;
+#if defined(__GNUC__) && (__GNUC__ < 3)
   MatrixRow(const MatrixRow&);		// Not implemented and forbidden:
+#endif
   void operator = (const MatrixRow&);	// no cloning/assignment allowed
 public:					// Take a col of the matrix
   MatrixRow(Matrix& m, const int row) :
