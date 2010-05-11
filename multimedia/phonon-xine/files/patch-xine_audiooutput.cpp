--- ./xine/audiooutput.cpp
+++ ./xine/audiooutput.cpp
@@ -48,6 +48,7 @@
 
 AudioOutput::AudioOutput(QObject *parent)
     : AbstractAudioOutput(new AudioOutputXT, parent)
+    , m_volume(1.0)
 {
 }
 