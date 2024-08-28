--- src/wxMaxima.cpp.orig	2024-08-28 07:18:18 UTC
+++ src/wxMaxima.cpp
@@ -3520,8 +3520,6 @@ void wxMaxima::VariableActionMaximaHtmldir(const wxStr
   if(GetWorksheet())
     {
       GetWorksheet()->SetMaximaDocDir(dir_canonical);
-      GetWorksheet()->LoadHelpFileAnchors(dir_canonical,
-                                          m_configuration.GetMaximaVersion());
     }
 }
 void wxMaxima::GnuplotCommandName(wxString gnuplot) {
