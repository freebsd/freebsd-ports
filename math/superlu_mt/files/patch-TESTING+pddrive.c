--- TESTING/pddrive.c.orig	2008-06-18 22:06:40.000000000 -0500
+++ TESTING/pddrive.c	2008-06-18 22:08:38.000000000 -0500
@@ -9,6 +9,11 @@
 #define	FMT2      "%10s:fact=%d, trans=%d, refact=%d, equed=%d, n=%d, imat=%d, test(%d)=%12.5g\n"
 #define FMT3      "%10s:info=%d, izero=%d, n=%d, nrhs=%d, imat=%d, nfail=%d\n"
 
+/* SuperLU compatibility */
+#define DN SLU_DN
+#define _D SLU_D
+#define GE SLU_GE
+#define NC SLU_NC
 
 main(int argc, char *argv[])
 {
