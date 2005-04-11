--- clientgui/MainFrame.cpp.orig	Sat Mar 12 01:51:31 2005
+++ clientgui/MainFrame.cpp	Thu Mar 24 11:12:36 2005
@@ -1106,7 +1106,6 @@
                     wxString strConnectedMachine = wxEmptyString;
                     wxString strStatusText = wxEmptyString;
                     wxString strTitle = m_strBaseTitle;
-                    wxString strLocale = setlocale(LC_NUMERIC, NULL);
      
                     pDoc->GetConnectedComputerName( strConnectedMachine );
                     if ( strConnectedMachine.empty() )
@@ -1119,9 +1118,7 @@
                         strStatusText += strConnectedMachine;
                     }
 
-                    setlocale(LC_NUMERIC, "C");
                     strBuffer.Printf(wxT("%.2f"), pDoc->GetCoreClientVersion()/100.0);
-                    setlocale(LC_NUMERIC, strLocale.c_str());
 
                     strTitle.Printf(_("%s - (%s)"), m_strBaseTitle.c_str(), strConnectedMachine.c_str());
                     strStatusText.Printf(_("Connected to %s (%s)"), strConnectedMachine.c_str(), strBuffer.c_str());
