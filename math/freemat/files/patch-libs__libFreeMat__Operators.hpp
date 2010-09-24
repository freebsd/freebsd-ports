--- ./libs/libFreeMat/Operators.hpp.orig	2009-10-09 02:24:22.000000000 -0400
+++ ./libs/libFreeMat/Operators.hpp	2010-09-21 14:32:02.000000000 -0400
@@ -142,11 +142,11 @@
   if (!Bcast.isScalar()) Bcast = Bcast.asDenseArray();
   if (Acast.isScalar() && Bcast.isScalar()) {
     if (Acast.allReal() && Bcast.allReal()) {
-      F = Array::Array(Op::func(Acast.constRealScalar<T>(),
+      F = Array(Op::func(Acast.constRealScalar<T>(),
 				Bcast.constRealScalar<T>()));
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(T(0),T(0));
+      F = Array(T(0),T(0));
       Op::func(Acast.constRealScalar<T>(),
 	       Acast.constImagScalar<T>(),
 	       Bcast.constRealScalar<T>(),
@@ -155,7 +155,7 @@
     }
   } else if (Acast.isScalar()) {
     if (Acast.allReal() && Bcast.allReal()) {
-      F = Array::Array(Tclass,Bcast.dimensions());
+      F = Array(Tclass,Bcast.dimensions());
       T* ret = F.real<T>().data();
       const T& Ap = Acast.constRealScalar<T>();
       const T* Bp = Bcast.constReal<T>().constData();
@@ -163,7 +163,7 @@
       for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap,Bp[i]);
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Tclass,Bcast.dimensions());
+      F = Array(Tclass,Bcast.dimensions());
       T* Cr = F.real<T>().data();
       T* Ci = F.imag<T>().data();
       const T& Ar = Acast.constRealScalar<T>();
@@ -175,7 +175,7 @@
     }
   } else if (Bcast.isScalar()) {
     if (Bcast.allReal() && Acast.allReal()) {
-      F = Array::Array(Tclass,Acast.dimensions());
+      F = Array(Tclass,Acast.dimensions());
       T* ret = F.real<T>().data();
       const T* Ap = Acast.constReal<T>().constData();
       const T& Bp = Bcast.constRealScalar<T>();
@@ -183,7 +183,7 @@
       for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap[i],Bp);
     } else { 
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Tclass,Acast.dimensions());
+      F = Array(Tclass,Acast.dimensions());
       T* Cr = F.real<T>().data();
       T* Ci = F.imag<T>().data();
       const T* Ar = Acast.constReal<T>().constData();
@@ -197,7 +197,7 @@
     if (Acast.dimensions() != Bcast.dimensions())
       throw Exception("size mismatch in arguments to binary operator");
     if (Bcast.allReal() && Acast.allReal()) {
-      F = Array::Array(Tclass,Acast.dimensions());
+      F = Array(Tclass,Acast.dimensions());
       T* ret = F.real<T>().data();
       const T* Ap = Acast.constReal<T>().constData();
       const T* Bp = Bcast.constReal<T>().constData();
@@ -205,7 +205,7 @@
       for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap[i],Bp[i]);
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Tclass,Acast.dimensions());
+      F = Array(Tclass,Acast.dimensions());
       T* Cr = F.real<T>().data();
       T* Ci = F.imag<T>().data();
       const T* Ar = Acast.constReal<T>().constData();
@@ -328,17 +328,17 @@
   if (!Acast.isScalar()) Acast = Acast.asDenseArray();
   if (!Bcast.isScalar()) Bcast = Bcast.asDenseArray();
   if (Acast.isScalar() && Bcast.isScalar()) {
-    F = Array::Array(Op::func(Acast.constRealScalar<T>(),
+    F = Array(Op::func(Acast.constRealScalar<T>(),
 			      Bcast.constRealScalar<T>()));
   } else if (Acast.isScalar()) {
-    F = Array::Array(Bool,Bcast.dimensions());
+    F = Array(Bool,Bcast.dimensions());
     bool* ret = F.real<bool>().data();
     const T& Ap = Acast.constRealScalar<T>();
     const T* Bp = Bcast.constReal<T>().constData();
     uint64 q = uint64(Bcast.length());
     for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap,Bp[i]);
   } else if (Bcast.isScalar()) {
-    F = Array::Array(Bool,Acast.dimensions());
+    F = Array(Bool,Acast.dimensions());
     bool* ret = F.real<bool>().data();
     const T* Ap = Acast.constReal<T>().constData();
     const T& Bp = Bcast.constRealScalar<T>();
@@ -347,7 +347,7 @@
   } else {
     if (Acast.dimensions() != Bcast.dimensions())
       throw Exception("size mismatch in arguments to binary operator");
-    F = Array::Array(Bool,Acast.dimensions());
+    F = Array(Bool,Acast.dimensions());
     bool* ret = F.real<bool>().data();
     const T* Ap = Acast.constReal<T>().constData();
     const T* Bp = Bcast.constReal<T>().constData();
@@ -395,18 +395,18 @@
   if (!Bcast.isScalar()) Bcast = Bcast.asDenseArray();
   if (Acast.isScalar() && Bcast.isScalar()) {
     if (Acast.allReal() && Bcast.allReal()) {
-      F = Array::Array(Op::func(Acast.constRealScalar<T>(),
+      F = Array(Op::func(Acast.constRealScalar<T>(),
 				Bcast.constRealScalar<T>()));
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Op::func(Acast.constRealScalar<T>(),
+      F = Array(Op::func(Acast.constRealScalar<T>(),
 				Acast.constImagScalar<T>(),
 				Bcast.constRealScalar<T>(),
 				Bcast.constImagScalar<T>()));
     }
   } else if (Acast.isScalar()) {
     if (Acast.allReal() && Bcast.allReal()) {
-      F = Array::Array(Bool,Bcast.dimensions());
+      F = Array(Bool,Bcast.dimensions());
       bool* ret = F.real<bool>().data();
       const T& Ap = Acast.constRealScalar<T>();
       const T* Bp = Bcast.constReal<T>().constData();
@@ -414,7 +414,7 @@
       for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap,Bp[i]);
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Bool,Bcast.dimensions());
+      F = Array(Bool,Bcast.dimensions());
       bool* ret = F.real<bool>().data();
       const T& Ar = Acast.constRealScalar<T>();
       const T& Ai = Acast.constImagScalar<T>();
@@ -425,7 +425,7 @@
     }
   } else if (Bcast.isScalar()) {
     if (Bcast.allReal() && Acast.allReal()) {
-      F = Array::Array(Bool,Acast.dimensions());
+      F = Array(Bool,Acast.dimensions());
       bool* ret = F.real<bool>().data();
       const T* Ap = Acast.constReal<T>().constData();
       const T& Bp = Bcast.constRealScalar<T>();
@@ -433,7 +433,7 @@
       for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap[i],Bp);
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Bool,Acast.dimensions());
+      F = Array(Bool,Acast.dimensions());
       bool* ret = F.real<bool>().data();
       const T* Ar = Acast.constReal<T>().constData();
       const T* Ai = Acast.constImag<T>().constData();
@@ -446,7 +446,7 @@
     if (Acast.dimensions() != Bcast.dimensions())
       throw Exception("size mismatch in arguments to binary operator");
     if (Bcast.allReal() && Acast.allReal()) {
-      F = Array::Array(Bool,Acast.dimensions());
+      F = Array(Bool,Acast.dimensions());
       bool* ret = F.real<bool>().data();
       const T* Ap = Acast.constReal<T>().constData();
       const T* Bp = Bcast.constReal<T>().constData();
@@ -454,7 +454,7 @@
       for (uint64 i=0;i<q;i++) ret[i] = Op::func(Ap[i],Bp[i]);
     } else {
       Acast.forceComplex(); Bcast.forceComplex();
-      F = Array::Array(Bool,Acast.dimensions());
+      F = Array(Bool,Acast.dimensions());
       bool* ret = F.real<bool>().data();
       const T* Ar = Acast.constReal<T>().constData();
       const T* Ai = Acast.constImag<T>().constData();
@@ -533,9 +533,9 @@
   if (!Acast.isScalar()) Acast = Acast.asDenseArray();
   if (Acast.isScalar()) {
     if (Acast.allReal()) {
-      F = Array::Array(Op::func(Acast.constRealScalar<T>()));
+      F = Array(Op::func(Acast.constRealScalar<T>()));
     } else {
-      F = Array::Array(T(0),T(0));
+      F = Array(T(0),T(0));
       Op::func(Acast.constRealScalar<T>(),
 	       Acast.constImagScalar<T>(),
 	       F.realScalar<T>(),F.imagScalar<T>());
