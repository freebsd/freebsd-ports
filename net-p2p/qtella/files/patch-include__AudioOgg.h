--- include/AudioOgg.h.otih	Tue May 29 17:25:30 2007
+++ include/AudioOgg.h	Tue May 29 17:27:46 2007
@@ -11,7 +11,7 @@
 class AudioOgg: public MyAudioFile
 {
 public:
-  AudioOgg::AudioOgg( std::string filename );
+  AudioOgg( std::string filename );
   std::string	&getTitle()	{ return _title; };
   void		setTitle( std::string str ) { _title = str; }
   std::string	&getArtist()	{ return _artist;} ;
