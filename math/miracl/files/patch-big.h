--- ./big.h.orig	2012-03-07 16:18:08.000000000 -0600
+++ ./big.h	2014-04-10 22:50:46.942771472 -0500
@@ -299,7 +299,7 @@
               {if (mr_compare(b1.fn,b2.fn)>0) return TRUE; else return FALSE;}
 
     friend Big from_binary(int,char *);
-    friend int to_binary(const Big&,int,char *,BOOL justify=FALSE);
+    friend int to_binary(const Big&,int,char *,BOOL justify);
     friend Big modmult(const Big&,const Big&,const Big&);
     friend Big mad(const Big&,const Big&,const Big&,const Big&,Big&);
     friend Big norm(const Big&);
@@ -321,7 +321,7 @@
                                                          // x^m.y^k mod n 
     friend Big pow(int,Big *,Big *,Big);  // x[0]^m[0].x[1].m[1]... mod n
 
-    friend Big luc(const Big& ,const Big&, const Big&, Big *b4=NULL);
+    friend Big luc(const Big& ,const Big&, const Big&, Big *b4);
 	friend Big moddiv(const Big&,const Big&,const Big&);
     friend Big inverse(const Big&, const Big&);
     friend void multi_inverse(int,Big*,const Big&,Big *);
@@ -353,8 +353,8 @@
     friend void modulo(const Big&);
     friend BOOL modulo(int,int,int,int,BOOL);
     friend Big get_modulus(void);
-    friend int window(const Big&,int,int*,int*,int window_size=5);
-    friend int naf_window(const Big&,const Big&,int,int*,int*,int store=11);
+    friend int window(const Big&,int,int*,int*,int window_size);
+    friend int naf_window(const Big&,const Big&,int,int*,int*,int store);
     friend void jsf(const Big&,const Big&,Big&,Big&,Big&,Big&);
 
 /* Montgomery stuff */
@@ -420,7 +420,10 @@
 extern Big rand(int,int); 
 extern Big strong_rand(csprng *,int,int);
 extern Big from_binary(int,char *);
-extern int to_binary(const Big&,int,char *,BOOL);
+extern int to_binary(const Big&,int,char *,BOOL=false);
+extern Big luc(const Big& ,const Big&, const Big&, Big *b4=NULL);
+extern int window(const Big&,int,int*,int*,int window_size=5);
+extern int naf_window(const Big&,const Big&,int,int*,int*,int store=11);
 
 using namespace std;
 
