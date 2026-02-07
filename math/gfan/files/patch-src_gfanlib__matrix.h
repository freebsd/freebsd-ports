--- src/gfanlib_matrix.h.orig	2017-06-20 14:47:37 UTC
+++ src/gfanlib_matrix.h
@@ -115,6 +115,7 @@ template <class typ> class Matrix{ (public)
         	  p[i][j]=s*(q[i][j]);
       return p;
     }
+#if 0
   friend Matrix operator*(const Matrix& a, const Matrix& b)
     {
       assert(a.width==b.height);
@@ -123,6 +124,7 @@ template <class typ> class Matrix{ (public)
         ret[i]=a.vectormultiply(b.column(i));
       return ret.transposed();
     }
+#endif
   /*  template<class T>
     Matrix<T>(const Matrix<T>& c):v(c.size()){
     for(int i=0;i<size();i++)v[i]=typ(c[i]);}
