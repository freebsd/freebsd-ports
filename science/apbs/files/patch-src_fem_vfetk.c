-- Match Vfetk_PDE_u_T definition to the FETK mc PDE struct used in the
-- bundled FETK source, which passes an additional dF[][3] gradient argument.
--- src/fem/vfetk.c.orig	2022-04-29 11:53:08.000000000 -0700
+++ src/fem/vfetk.c	2026-09-26 18:39:59.361220000 -0700
@@ -1884,15 +1884,9 @@
  * similar signature change. - P. Ellis 11-8-2011
  */
 VPUBLIC void Vfetk_PDE_u_T(PDE *thee, int type, int chart, double txq[],
-  double F[]) {
-/*VPUBLIC void Vfetk_PDE_u_T(sPDE *thee,
-                           int type,
-                           int chart,
-                           double txq[],
-                           double F[],
-                           double dF[][3]
-                          ) { */
+  double F[], double dF[][3]) {

+    (void)dF;
     F[0] = 0.0;
     var.u_T = F[0];

