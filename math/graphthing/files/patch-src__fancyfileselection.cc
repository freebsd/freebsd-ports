--- src/fancyfileselection.cc.orig	2006-09-11 10:32:12.000000000 +0900
+++ src/fancyfileselection.cc	2012-02-13 23:12:49.000000000 +0900
@@ -21,6 +21,10 @@
 	{ "Postscript", ".ps" }
 };
 
+#if !WXWIN_COMPATIBILITY_2_4
+# define wxHIDE_READONLY 0
+#endif
+
 FancyFileSelection::FancyFileSelection (wxWindow *parent, const wxString &title,
 					long style, bool file_types,
 					const wxString &mask)
@@ -30,7 +34,7 @@
 		style |= wxHIDE_READONLY;
 	else if (style & wxSAVE)
 		style |= wxOVERWRITE_PROMPT;
-	SetStyle (style);
+	SetWindowStyle (style);
 
 	if (file_types) {
 		wxString wc = wxT("");
