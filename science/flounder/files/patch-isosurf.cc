--- src/isosurf.cc.orig	Tue Oct 15 02:05:22 2002
+++ src/isosurf.cc	Tue Oct 15 02:07:26 2002
@@ -138,7 +138,7 @@
  * 						 N.B. the array is subscripted as data[z][y][x]
  */
 void
-Isosurf::alloc_3d_data_array(int nx, int ny, int nz, float *dp = NULL)
+Isosurf::alloc_3d_data_array(int nx, int ny, int nz, float *dp)
 {
     register int i, j;
 
@@ -550,7 +550,7 @@
 int dfprintf(int fd, int i);
 /**************************************************************/
 
-int perr(char *s, int a1=0, int a2=0, int a3=0, int a4=0, int a5=0, int a6=0)
+int perr(char *s, int a1, int a2, int a3, int a4, int a5, int a6)
 {
     fprintf(stderr, "%s: ", Progname);
     fprintf(stderr, s, a1, a2, a3, a4, a5, a6);
@@ -2241,7 +2241,6 @@
 * the University of Illinois at Urbana-Champaign.
 */
 
-#include <malloc.h>
 
 /********************************************************/
 float    *
