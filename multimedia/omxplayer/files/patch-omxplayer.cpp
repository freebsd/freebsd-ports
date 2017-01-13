--- omxplayer.cpp.orig	2015-10-24 12:09:14 UTC
+++ omxplayer.cpp
@@ -84,8 +86,8 @@ bool              m_osd                 
 bool              m_no_keys             = false;
 std::string       m_external_subtitles_path;
 bool              m_has_external_subtitles = false;
-std::string       m_font_path           = "/usr/share/fonts/truetype/freefont/FreeSans.ttf";
-std::string       m_italic_font_path    = "/usr/share/fonts/truetype/freefont/FreeSansOblique.ttf";
+std::string       m_font_path           = "LOCALBASE/share/fonts/freefont-ttf/FreeSans.ttf";
+std::string       m_italic_font_path    = "LOCALBASE/share/fonts/freefont-ttf/FreeSansOblique.ttf";
 std::string       m_dbus_name           = "org.mpris.MediaPlayer2.omxplayer";
 bool              m_asked_for_font      = false;
 bool              m_asked_for_italic_font = false;
