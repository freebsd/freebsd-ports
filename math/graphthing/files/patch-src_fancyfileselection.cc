--- src/fancyfileselection.cc.orig	2006-09-11 01:32:12 UTC
+++ src/fancyfileselection.cc
@@ -21,6 +21,10 @@ static struct {
 	{ "Postscript", ".ps" }
 };
 
+#if !WXWIN_COMPATIBILITY_2_4
+# define wxHIDE_READONLY 0
+#endif
+
 FancyFileSelection::FancyFileSelection (wxWindow *parent, const wxString &title,
 					long style, bool file_types,
 					const wxString &mask)
@@ -30,7 +34,7 @@ FancyFileSelection::FancyFileSelection (
 		style |= wxHIDE_READONLY;
 	else if (style & wxSAVE)
 		style |= wxOVERWRITE_PROMPT;
-	SetStyle (style);
+	SetWindowStyle (style);
 
 	if (file_types) {
 		wxString wc = wxT("");
