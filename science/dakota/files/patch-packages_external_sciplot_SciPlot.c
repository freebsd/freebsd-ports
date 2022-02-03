- reported to the ML on 2022-02-01

--- packages/external/sciplot/SciPlot.c.orig	2022-02-01 09:03:55 UTC
+++ packages/external/sciplot/SciPlot.c
@@ -3761,7 +3761,7 @@ realpair* SciPlotListReturnPtr (Widget wi, int idnum, 
   SciPlotList *p;
   SciPlotWidget w;
   if (!XtIsSciPlot(wi))
-    return;
+    return NULL;
   w = (SciPlotWidget) wi;
 
   p = _ListFind(w, idnum);
@@ -3792,7 +3792,7 @@ Boolean SciPlotQuickUpdateCheck (Widget wi)
 {
   SciPlotWidget w;
   if (!XtIsSciPlot(wi))
-    return;
+    return NULL;
   w = (SciPlotWidget) wi;
 
   return CheckMinMax(w);
