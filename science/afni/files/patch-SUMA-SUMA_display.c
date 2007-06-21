--- SUMA/SUMA_display.c.orig	Wed Jun  6 12:42:06 2007
+++ SUMA/SUMA_display.c	Wed Jun  6 12:45:54 2007
@@ -1854,22 +1854,14 @@
          
  
          
-      #ifdef SUMA_MOTIF_GLXAREA
-        /* Step 4. */
-        SUMAg_SVv[ic].X->FORM = XmCreateForm(SUMAg_SVv[ic].X->TOPLEVEL, "form", NULL, 0);
-        XtManageChild(SUMAg_SVv[ic].X->FORM);
-        SUMAg_SVv[ic].X->FRAME = XmCreateFrame(SUMAg_SVv[ic].X->FORM, "frame", NULL, 0);
-        XtVaSetValues(SUMAg_SVv[ic].X->FRAME,
-          XmNbottomAttachment, XmATTACH_FORM,
-          XmNtopAttachment, XmATTACH_FORM,
-          XmNleftAttachment, XmATTACH_FORM,
-          XmNrightAttachment, XmATTACH_FORM,
-          NULL);
-        XtManageChild(SUMAg_SVv[ic].X->FRAME);
-
-        /* Step 5. */
         SUMAg_SVv[ic].X->CMAP = SUMA_getShareableColormap(&(SUMAg_SVv[ic]));
 
+        /* create a frame to put glxarea in */
+        SUMAg_SVv[ic].X->FRAME = XmCreateFrame (mainw, "frame", NULL, 0);
+        XtManageChild(SUMAg_SVv[ic].X->FRAME);
+
+      #ifdef SUMA_MOTIF_GLXAREA
+        SUMA_LH("MOTIF Drawing Area");
         /* Step 6. */
          /* glwMDrawingAreaWidgetClass requires libMesaGLwM.a */
          SUMAg_SVv[ic].X->GLXAREA = XtVaCreateManagedWidget("glxarea",
@@ -1878,20 +1870,13 @@
           XtNcolormap, SUMAg_SVv[ic].X->CMAP,
           NULL);
       #else
-      /* Step 4-6. */
-         SUMAg_SVv[ic].X->CMAP = SUMA_getShareableColormap(&(SUMAg_SVv[ic]));
-
-         /* create a frame to put glxarea in */
-         SUMAg_SVv[ic].X->FRAME  = XmCreateFrame (mainw, "frame", NULL, 0);
-         XtManageChild(SUMAg_SVv[ic].X->FRAME);
-
+        SUMA_LH("GL Drawing Area");
          /* glwDrawingAreaWidgetClass requires libMesaGLw.a */
          SUMAg_SVv[ic].X->GLXAREA = XtVaCreateManagedWidget("glxarea",
           glwDrawingAreaWidgetClass, SUMAg_SVv[ic].X->FRAME,
           GLwNvisualInfo, SUMAg_SVv[ic].X->VISINFO,
           XtNcolormap, SUMAg_SVv[ic].X->CMAP,
           NULL);
-      
       #endif
 
           
