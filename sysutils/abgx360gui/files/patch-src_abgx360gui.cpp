src/abgx360gui.cpp:2459:66: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
            str = wxT("Your StealthFiles folder is located here:"NEWLINE);
                                                                 ^

--- src/abgx360gui.cpp.orig	2018-08-01 13:21:47 UTC
+++ src/abgx360gui.cpp
@@ -1007,7 +1007,7 @@ void abgx360gui::OnClose(wxCloseEvent& WXUNUSED(event)
 void abgx360gui::MnuSaveSettingsClick(wxCommandEvent& WXUNUSED(event))
 {
     wxString name = wxT("/Settings/");
-	name += wxGetTextFromUser(wxT("Enter a name for these settings. Saving them as \"Default\" will"NEWLINE"cause them to be loaded every time abgx360 GUI is launched."), wxT("Save Settings"), wxT("Default"));
+	name += wxGetTextFromUser(wxT("Enter a name for these settings. Saving them as \"Default\" will" NEWLINE "cause them to be loaded every time abgx360 GUI is launched."), wxT("Save Settings"), wxT("Default"));
 	
 	if (name.Cmp(wxT("/Settings/")) == 0) return;
 	
@@ -1908,7 +1908,7 @@ void abgx360gui::OpenButtonClick(wxCommandEvent& WXUNU
             //m_fileHistory->AddFileToHistory(openfilename);
             count = arrayStringFor_OpenFileDialog.GetCount();
             if (count > 100) {
-                wxMessageBox(wxT("You have selected over 100 files!"NEWLINE"This will probably exceed maximum command line length limits so try using directory input instead."), wxT("Doh!"), wxICON_EXCLAMATION);
+                wxMessageBox(wxT("You have selected over 100 files!" NEWLINE "This will probably exceed maximum command line length limits so try using directory input instead."), wxT("Doh!"), wxICON_EXCLAMATION);
               return;
             }
             if (count) {
@@ -2456,7 +2456,7 @@ void abgx360gui::WhereStealthFilesClick(wxCommandEvent
         homedir += wxT("\\abgx360\\");
     #else
         if (wxGetEnv(wxT("ABGX360_DIR"), &homedir) || wxGetEnv(wxT("HOME"), &homedir)) {
-            str = wxT("Your StealthFiles folder is located here:"NEWLINE);
+            str = wxT("Your StealthFiles folder is located here:" NEWLINE);
         }
         else {
             wxMessageBox(wxT("ERROR: Unable to find your StealthFiles folder!"), wxT("Where is my StealthFiles folder?"), wxOK);
@@ -2503,7 +2503,7 @@ void abgx360gui::WhereImagesClick(wxCommandEvent& even
         homedir += wxT("\\abgx360\\");
     #else
         if (wxGetEnv(wxT("ABGX360_DIR"), &homedir) || wxGetEnv(wxT("HOME"), &homedir)) {
-            str = wxT("Your Images folder is located here:"NEWLINE);
+            str = wxT("Your Images folder is located here:" NEWLINE);
         }
         else {
             wxMessageBox(wxT("ERROR: Unable to find your Images folder!"), wxT("Where is my Images folder?"), wxOK);
@@ -2567,7 +2567,7 @@ bool DnDInput::OnDropFiles(wxCoord, wxCoord, const wxA
                 if (realcount) {
                     dndeditbox->AppendText(wxT(" "));
                     if (realcount >= 100) {
-                        wxMessageBox(wxT("You have selected over 100 files!"NEWLINE"This will probably exceed maximum command line length limits so try using directory input instead."), wxT("Doh!"), wxICON_EXCLAMATION);
+                        wxMessageBox(wxT("You have selected over 100 files!" NEWLINE "This will probably exceed maximum command line length limits so try using directory input instead."), wxT("Doh!"), wxICON_EXCLAMATION);
                         dndeditbox->Clear();
                       return false;
                     }
