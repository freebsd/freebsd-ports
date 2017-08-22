--- src/ui/gui/pspp-sheet-view-column.h.orig	2017-08-18 10:51:13 UTC
+++ src/ui/gui/pspp-sheet-view-column.h
@@ -40,6 +40,10 @@
 
 G_BEGIN_DECLS
 
+#ifndef PSEAL
+#define PSEAL(X) X
+#endif
+
 #define PSPP_TYPE_SHEET_VIEW_COLUMN	     (pspp_sheet_view_column_get_type ())
 #define PSPP_SHEET_VIEW_COLUMN(obj)	     (G_TYPE_CHECK_INSTANCE_CAST ((obj), PSPP_TYPE_SHEET_VIEW_COLUMN, PsppSheetViewColumn))
 #define PSPP_SHEET_VIEW_COLUMN_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), PSPP_TYPE_SHEET_VIEW_COLUMN, PsppSheetViewColumnClass))
