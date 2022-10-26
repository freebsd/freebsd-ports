--- src/saga_core/saga_gui/dlg_about.cpp.orig	2022-09-14 15:41:47 UTC
+++ src/saga_core/saga_gui/dlg_about.cpp
@@ -166,12 +166,7 @@ wxString CDLG_About::_Get_Version(void)
 	#else
 		s	+= " (32 bit)</b><br>";
 	#endif
-	#ifdef GIT_HASH
-		if( *GIT_HASH )
-		{
-			s	+= "<br><i>Git commit hash</i><br>[ <a href=\"https://sourceforge.net/p/saga-gis/code/ci/" GIT_HASH "\">#" GIT_HASH "</a> ]<br>";
-		}
-	#endif
+		s	+= "<br><i>Git commit hash</i><br>[ <a href=\"https://sourceforge.net/p/saga-gis/code/ci/GIT_TAGNAME \">#" + wxString("GIT_TAGNAME") + "</a> ]<br>";
 	s	+= "<br>";
 	s	+= "<a href=\"https://saga-gis.sourceforge.io/\">saga-gis.org</a>";
 
