--- src/utils/wxCas/src/wxcasframe.cpp~
+++ src/utils/wxCas/src/wxcasframe.cpp
@@ -285,11 +285,11 @@ WxCasFrame::GetStatImage () const
 #ifdef __WXMSW__
 
 	memdc.
-	SetFont ( wxFont::wxFont ( 6, wxSWISS, wxNORMAL, wxBOLD ) );
+	SetFont ( wxFont ( 6, wxSWISS, wxNORMAL, wxBOLD ) );
 #else
 
 	memdc.
-	SetFont ( wxFont::wxFont ( 8, wxSWISS, wxNORMAL, wxBOLD ) );
+	SetFont ( wxFont ( 8, wxSWISS, wxNORMAL, wxBOLD ) );
 #endif
 
 	memdc.
