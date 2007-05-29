--- include/AudioWav.h.orig	Tue May 29 17:25:24 2007
+++ include/AudioWav.h	Tue May 29 17:27:38 2007
@@ -11,7 +11,7 @@
 class AudioWav: public MyAudioFile
 {
 public:
-  AudioWav::AudioWav( std::string filename );
+  AudioWav( std::string filename );
   std::string	&getTitle()	{ return _title; };
   std::string	&getArtist()	{ return _artist;} ;
 //  std::string	&getAlbum()	{ return _album; };
