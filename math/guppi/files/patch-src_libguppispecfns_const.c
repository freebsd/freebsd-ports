--- src/libguppispecfns/const.c.orig	Tue Apr  1 21:01:25 2003
+++ src/libguppispecfns/const.c	Tue Apr  1 21:01:35 2003
@@ -96,7 +96,9 @@
 #ifdef INFINITIES
 double INFINITY = 1.0 / 0.0;	/* 99e999; */
 #else
+#ifndef INFINITY
 double INFINITY = 1.79769313486231570815E308;	/* 2**1024*(1-MACHEP) */
+#endif
 #endif
 
 #ifdef MINUSZERO
