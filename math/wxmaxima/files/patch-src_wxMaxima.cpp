--- src/wxMaxima.cpp.orig	2023-02-04 19:03:25 UTC
+++ src/wxMaxima.cpp
@@ -3289,8 +3289,6 @@ void wxMaxima::VariableActionMaximaHtmldir(const wxStr
   wxLogMessage(wxString::Format(_("Maxima's HTML manuals are in directory %s"),
                                 dir_canonical.utf8_str()));
   m_worksheet->SetMaximaDocDir(dir_canonical);
-  m_worksheet->LoadHelpFileAnchors(dir_canonical,
-                                   m_worksheet->GetMaximaVersion());
 }
 void wxMaxima::GnuplotCommandName(wxString gnuplot) {
   m_gnuplotcommand = gnuplot;
