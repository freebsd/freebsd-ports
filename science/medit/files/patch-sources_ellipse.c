--- sources/ellipse.c.orig	2012-02-04 12:58:25.000000000 +0100
+++ sources/ellipse.c	2013-06-12 19:41:30.000000000 +0200
@@ -278,7 +278,7 @@
       m[0] = ps->m[0];
       m[1] = ps->m[1];
       m[2] = ps->m[2];
-      if ( !eigen2(m,lambda,vp) ) return;
+      if ( !eigen2(m,lambda,vp) ) return(0);
 
       /* consider eigenvalues as sizes */
       dd1 = 1.0 / sqrt(fabs(lambda[0]));
@@ -306,7 +306,7 @@
       m[0] = ps->m[0];
       m[1] = ps->m[1];
       m[2] = ps->m[2];
-      if ( !eigen2(m,lambda,vp) ) return;
+      if ( !eigen2(m,lambda,vp) ) return(0);
 
       /* consider eigenvalues as sizes */
       dd1 = 1.0 / sqrt(fabs(lambda[0]));
