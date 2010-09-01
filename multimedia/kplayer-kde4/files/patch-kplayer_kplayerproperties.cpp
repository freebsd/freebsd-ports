--- kplayer/kplayerproperties.cpp.orig	2010-06-15 12:54:50.164151273 +0300
+++ kplayer/kplayerproperties.cpp	2010-06-15 12:42:10.543902731 +0300
@@ -1788,7 +1788,7 @@ void KPlayerProperties::initialize (void
   info = new KPlayerBooleanPropertyInfo;
   m_info.insert ("Direct Rendering", info);
   strinfo = new KPlayerStringPropertyInfo;
-  strinfo -> setDefaultValue ("alsa");
+  strinfo -> setDefaultValue ("oss");
   m_info.insert ("Audio Driver", strinfo);
   info = new KPlayerStringPropertyInfo;
   m_info.insert ("Audio Device", info);
