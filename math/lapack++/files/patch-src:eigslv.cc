--- src/eigslv.cc~	Wed Mar  1 02:52:47 2000
+++ src/eigslv.cc	Wed May 22 21:49:45 2002
@@ -58,14 +58,14 @@
 //    char *fname = NULL;  // HP C++ does not support string initalization!
 //#endif
 
-    // view symmetric matrix S as a LaGenMatDouble
-    // assumes S is contiguous...
-    LaSymmMatDouble tmp(S);
-    LaEigSolveVecIP(tmp, eigvals);
-
-    LaGenMatDouble tmp2(&tmp(0,0), S.size(0), S.size(1));
-    eigvec.ref(tmp2);
-
+  long int N = S.size(0);
+  long int i,j;
+ 
+  for(j=0;j<N;j++){
+  for(i=j;i<N;i++){
+      eigvec(i,j)=S(i,j);
+    }}
+  LaEigSolveVecIP(eigvec, eigvals);
 
 }
 
@@ -100,18 +100,18 @@
 
 }
 
-void LaEigSolveVecIP(LaSymmMatDouble &S, LaVectorDouble &eigvals)
+void LaEigSolveVecIP(LaGenMatDouble &A, LaVectorDouble &eigvals)
 {   
 #ifndef HPPA
      const char fname[] = "LaEigSolveVecIP(LaGenMatDouble &A, &eigvals)";
 #else
     char *fname = NULL;  // HP C++ does not support string initalization!
 #endif
-    long int N = S.size(0);
+    long int N = A.size(0);
     char jobz = 'V';
     char uplo = 'L';
     long int info;
-    long int lda = S.gdim(0);
+    long int lda = A.gdim(0);
 
     if (eigvals.size() < N)
     {
@@ -119,11 +119,11 @@
     }
         
 
-    long int w = (LaEnvBlockSize("SSYTRD", S) +2) * N;
+    long int w = (LaEnvBlockSize("SSYTRD", A) +2) * N;
     LaVectorDouble Work(w);
 
 
-    F77NAME(dsyev)(&jobz, &uplo, &N, S.addr(), &lda, &eigvals(0), &Work(0),
+    F77NAME(dsyev)(&jobz, &uplo, &N, A.addr(), &lda, &eigvals(0), &Work(0),
         &w, &info);
 
     if (info != 0)
