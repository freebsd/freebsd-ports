--- server/mp4live/audio_faac.cpp.orig	2007-01-22 17:31:28 UTC
+++ server/mp4live/audio_faac.cpp
@@ -296,7 +296,7 @@ bool CFaacAudioEncoder::Init(void)
 
   debug_message("version = %d", m_faacConfig->version);
   debug_message("name = %s", m_faacConfig->name);
-  debug_message("allowMidside = %d", m_faacConfig->allowMidside);
+  //debug_message("allowMidside = %d", m_faacConfig->allowMidside);
   debug_message("useLfe = %d", m_faacConfig->useLfe);
   debug_message("useTns = %d", m_faacConfig->useTns);
   debug_message("bitRate = %lu", m_faacConfig->bitRate);
@@ -308,7 +308,9 @@ bool CFaacAudioEncoder::Init(void)
 
   m_faacConfig->mpegVersion = MPEG4;
   m_faacConfig->aacObjectType = LOW;
-  m_faacConfig->allowMidside = false;
+  //Do not set allowMidside for API compatibility with faac,
+  //see https://github.com/knik0/faac/issues/8 for details
+  //m_faacConfig->allowMidside = false;
   m_faacConfig->useLfe = false;
   m_faacConfig->useTns = false;
   m_faacConfig->inputFormat = FAAC_INPUT_16BIT;
