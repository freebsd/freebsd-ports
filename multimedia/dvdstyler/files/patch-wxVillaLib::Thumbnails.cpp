--- wxVillaLib/Thumbnails.cpp.orig	Thu Aug  5 06:15:33 2004
+++ wxVillaLib/Thumbnails.cpp	Thu Aug  5 06:17:33 2004
@@ -202,7 +202,7 @@
   wxString fname = wxFindFirstFile(m_dir + wxFILE_SEP_PATH + _T("*"));
   while (!fname.IsEmpty())
   {
-	wxString caption = m_showFileNames?fname.AfterLast(wxFILE_SEP_PATH):wxT("");
+	wxString caption = m_showFileNames? (const char *)fname.AfterLast(wxFILE_SEP_PATH):wxT("");
 	if ((m_filter & wxTHUMB_FILTER_VIDEOS &&
 	     (fname.AfterLast('.').Lower() == _T("mpg") ||
 		  fname.AfterLast('.').Lower() == _T("mpeg") ||
