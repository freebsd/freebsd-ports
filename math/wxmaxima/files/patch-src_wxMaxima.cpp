--- src/wxMaxima.cpp.orig	2023-12-25 16:45:03 UTC
+++ src/wxMaxima.cpp
@@ -3393,8 +3393,6 @@ void wxMaxima::VariableActionMaximaHtmldir(const wxStr
   wxLogMessage(_("Maxima's HTML manuals are in directory %s"),
                dir_canonical.utf8_str());
   GetWorksheet()->SetMaximaDocDir(dir_canonical);
-  GetWorksheet()->LoadHelpFileAnchors(dir_canonical,
-                                   GetWorksheet()->GetMaximaVersion());
 }
 void wxMaxima::GnuplotCommandName(wxString gnuplot) {
   m_gnuplotcommand = gnuplot;
