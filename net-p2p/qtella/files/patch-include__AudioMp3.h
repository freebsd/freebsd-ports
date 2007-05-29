--- include/AudioMp3.h.orig	Tue May 29 17:24:13 2007
+++ include/AudioMp3.h	Tue May 29 17:27:29 2007
@@ -11,7 +11,7 @@
 class AudioMp3: public MyAudioFile
 {
 public:
-  AudioMp3::AudioMp3( std::string filename );
+  AudioMp3( std::string filename );
   std::string	&getTitle()	{ return _title; };
   void		setTitle( std::string str ) { _title = str; };
   std::string	&getArtist()	{ return _artist;} ;
