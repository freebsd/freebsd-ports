--- iiimp/iiimpAux.c.orig	Wed Oct 13 21:13:37 2004
+++ iiimp/iiimpAux.c	Wed Oct 13 21:14:40 2004
@@ -1997,11 +1997,12 @@
 static void
 service_set_conversion_mode(aux_t * aux, int conversion_mode)
 {
+  XVaNestedList preedit_attr;
   XIC xic = (XIC)aux->ic;
   XIMPreeditState preedit_state;
 
   preedit_state = (conversion_mode == 1 ? XIMPreeditEnable : XIMPreeditDisable);
-  XVaNestedList preedit_attr = XVaCreateNestedList(0,
+  preedit_attr = XVaCreateNestedList(0,
 						   XNPreeditState, preedit_state,
 						   0);
   XSetICValues((XIC)xic,
