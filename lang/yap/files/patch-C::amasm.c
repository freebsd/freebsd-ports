--- C/amasm.c.orig	Sat Mar  6 02:56:11 2004
+++ C/amasm.c	Thu Sep  2 17:47:02 2004
@@ -430,9 +430,9 @@
   }
   cip->cpc = cip->cpc->nextInst;
   if (pass_no) {
-    ve = (Ventry *) cip->cpc->rnd1;
     OPREG var_offset;
-    int is_y_var = (ve->KindOfVE == PermVar);
+    ve = (Ventry *) cip->cpc->rnd1;
+    is_y_var = (ve->KindOfVE == PermVar);
 
     var_offset = Var_Ref(ve, is_y_var);
     code_p->u.oxx.xr = emit_xreg(var_offset);
