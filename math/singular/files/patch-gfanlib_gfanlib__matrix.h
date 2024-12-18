--- gfanlib/gfanlib_matrix.h.orig	2024-12-18 20:07:20 UTC
+++ gfanlib/gfanlib_matrix.h
@@ -115,6 +115,7 @@ template <class typ> class Matrix{ (public)
                   p[i][j]=s*(q[i][j]);
       return p;
     }
+  /*
   friend Matrix operator*(const Matrix& a, const Matrix& b)
     {
       assert(a.width==b.height);
@@ -123,6 +124,7 @@ template <class typ> class Matrix{ (public)
         ret[i]=a.vectormultiply(b.column(i));
       return ret.transposed();
     }
+  */
   /*  template<class T>
     Matrix<T>(const Matrix<T>& c):v(c.size()){
     for(int i=0;i<size();i++)v[i]=typ(c[i]);}
