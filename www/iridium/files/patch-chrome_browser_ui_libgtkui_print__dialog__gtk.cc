--- chrome/browser/ui/libgtkui/print_dialog_gtk.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/libgtkui/print_dialog_gtk.cc
@@ -347,6 +347,7 @@ void PrintDialogGtk2::ShowDialog(
   // Since we only generate PDF, only show printers that support PDF.
   // TODO(thestig) Add more capabilities to support?
   GtkPrintCapabilities cap = static_cast<GtkPrintCapabilities>(
+      GTK_PRINT_CAPABILITY_GENERATE_PS |
       GTK_PRINT_CAPABILITY_GENERATE_PDF |
       GTK_PRINT_CAPABILITY_PAGE_SET |
       GTK_PRINT_CAPABILITY_COPIES |
