--- src/HistoryDialog.vala.orig	2016-09-20 11:55:41 UTC
+++ src/HistoryDialog.vala
@@ -31,6 +31,10 @@ namespace PantheonCalculator {
         public signal void added (string text);
 
         public HistoryDialog (List<MainWindow.History?> _history) {
+            Intl.setlocale (LocaleCategory.ALL, "");
+            Intl.bind_textdomain_codeset (Build.GETTEXT_PACKAGE, "UTF-8");
+            Intl.textdomain (Build.GETTEXT_PACKAGE);
+
             history = _history;
             title = _("History");
             set_size_request (450, 0);
