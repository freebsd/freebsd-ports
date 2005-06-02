--- clientgui/MainFrame.cpp.orig	Sun May 29 03:12:00 2005
+++ clientgui/MainFrame.cpp	Wed Jun  1 20:58:56 2005
@@ -1323,7 +1323,6 @@
                     wxString strComputerName = wxEmptyString;
                     wxString strStatusText = wxEmptyString;
                     wxString strTitle = m_strBaseTitle;
-                    wxString strLocale = setlocale(LC_NUMERIC, NULL);
      
                     if (pDoc->IsReconnecting())
                         pDoc->GetConnectingComputerName(strComputerName);
