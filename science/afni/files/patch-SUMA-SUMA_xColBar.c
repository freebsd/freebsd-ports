--- SUMA/SUMA_xColBar.c.orig	Wed Jun  6 12:42:16 2007
+++ SUMA/SUMA_xColBar.c	Wed Jun  6 12:43:42 2007
@@ -4087,6 +4087,15 @@
          NULL);
       
       /* open me a glxarea */
+      #ifdef SUMA_MOTIF_GLXAREA
+         SO->SurfCont->cmp_ren->cmap_wid = XtVaCreateManagedWidget("glxarea",
+             glwMDrawingAreaWidgetClass, rcc2,
+             GLwNvisualInfo, SUMAg_SVv[0].X->VISINFO,
+             XtNcolormap, SUMAg_SVv[0].X->CMAP,
+             XmNwidth,   SUMA_CMAP_WIDTH,
+             XmNheight,  SUMA_CMAP_HEIGHT,
+             NULL);
+      #else
       SO->SurfCont->cmp_ren->cmap_wid = XtVaCreateManagedWidget("glxarea",
                                           glwDrawingAreaWidgetClass, rcc2,
                                           GLwNvisualInfo, SUMAg_SVv[0].X->VISINFO,
@@ -4094,6 +4103,7 @@
                                           XmNwidth,   SUMA_CMAP_WIDTH,
                                           XmNheight,  SUMA_CMAP_HEIGHT,
                                           NULL);
+      #endif
 
       XtManageChild (rcc2);
       
