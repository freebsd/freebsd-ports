--- tools/sources/feedback-gennet.c.orig	2008-04-21 16:56:07.000000000 +0900
+++ tools/sources/feedback-gennet.c	2012-10-24 04:47:13.000000000 +0900
@@ -48,7 +48,7 @@
  return 0.0;
 }
 
-void main ()
+int main(int argc, char **argv)
 {
  int i,j;
  int nin,nhid,nout,nconnections;
