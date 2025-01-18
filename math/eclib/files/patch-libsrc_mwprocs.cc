--- libsrc/mwprocs.cc.orig	2024-11-12 14:33:12 UTC
+++ libsrc/mwprocs.cc
@@ -94,25 +94,23 @@ vector<vector<bigfloat>> get_minor(const vector<vector
 
 vector<vector<bigfloat>> get_minor(const vector<vector<bigfloat>>& m, long m_size, long i0, long j0)
 {
-  vector<vector<bigfloat>> minor(MAXRANK, vector<bigfloat>(MAXRANK));
+  vector<vector<bigfloat>> the_minor(MAXRANK, vector<bigfloat>(MAXRANK));
   for (long i=0; i<m_size-1; i++)
     {
-      long ii=i;
-      if(i>=i0) ii++;
+      long ii = (i>=i0? i+1 : i);
       for (long j=0; j<m_size-1; j++)
       {
-	long jj=j;
+	long jj = (j>=j0? j+1 : j);
         if(j>=j0) jj++;
-	minor[i][j] = m[ii][jj];
+	the_minor[i][j] = m[ii][jj];
       }
     }
-  return minor;
+  return the_minor;
 }
 
 bigfloat det_minor(const vector<vector<bigfloat>>& m, long m_size, long i0, long j0)
 {
-  const vector<vector<bigfloat>>& minor = get_minor(m,m_size,i0,j0);
-  return det(minor, m_size-1);
+  return det(get_minor(m,m_size,i0,j0), m_size-1);
 }
 
 bigfloat det(const vector<vector<bigfloat>>& m, long m_size)
