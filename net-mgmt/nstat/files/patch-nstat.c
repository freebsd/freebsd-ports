--- nstat.c.orig	2018-07-26 14:34:20 UTC
+++ nstat.c
@@ -53,6 +53,7 @@
 
 
 /* why is this only defined in the kernel */
+#undef timespecadd
 #define	timespecadd(vvp, uvp)						\
 	do {								\
 		(vvp)->tv_sec += (uvp)->tv_sec;				\
