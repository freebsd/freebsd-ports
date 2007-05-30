--- xgv_anchor.c.orig	Wed May 30 21:06:33 2007
+++ xgv_anchor.c	Wed May 30 21:08:22 2007
@@ -34,20 +34,20 @@
 #include "DrawingA.h"
 #include "xgvis.h"
 
-void xgv_shift_clust_widgets(xgobidata *);
-void xgv_alloc_clust(xgobidata *);
-void xgv_addGroup(int, Widget, xgobidata *);
-void xgv_draw_cluster_symbol(xgobidata *, int);
-void xgv_mark_cluster_symbol(xgobidata *, int, int);
-void xgv_create_clust_widgets(xgobidata *);
+static void xgv_shift_clust_widgets(xgobidata *);
+static void xgv_alloc_clust(xgobidata *);
+static void xgv_addGroup(int, Widget, xgobidata *);
+static void xgv_draw_cluster_symbol(xgobidata *, int);
+static void xgv_mark_cluster_symbol(xgobidata *, int, int);
+static void xgv_create_clust_widgets(xgobidata *);
 XtCallbackProc xgv_reset_clusters_cback (Widget, xgobidata *, XtPointer);
 XtCallbackProc xgv_open_anchor_popup_cback(Widget, xgobidata *, XtPointer);
-XtCallbackProc xgv_symbol_reset_cb(Widget, xgobidata *, XawDrawingAreaCallbackStruct *);
-XtCallbackProc xgv_anchor_cback(Widget, xgobidata *, XtPointer);
-XtCallbackProc xgv_close_cback(Widget, xgobidata *, XtPointer);
-XtCallbackProc xgv_symbol_expose_cb(Widget, xgobidata *, XawDrawingAreaCallbackStruct *);
-XtCallbackProc xgv_exclude_cback(Widget, xgobidata *, XtPointer);
-XtCallbackProc xgv_hide_cback(Widget, xgobidata *, XtPointer);
+static XtCallbackProc xgv_symbol_reset_cb(Widget, xgobidata *, XawDrawingAreaCallbackStruct *);
+static XtCallbackProc xgv_anchor_cback(Widget, xgobidata *, XtPointer);
+static XtCallbackProc xgv_close_cback(Widget, xgobidata *, XtPointer);
+static XtCallbackProc xgv_symbol_expose_cb(Widget, xgobidata *, XawDrawingAreaCallbackStruct *);
+static XtCallbackProc xgv_exclude_cback(Widget, xgobidata *, XtPointer);
+static XtCallbackProc xgv_hide_cback(Widget, xgobidata *, XtPointer);
 
 extern void save_group_names(xgobidata *);
 extern void save_brush_groups(xgobidata *);
