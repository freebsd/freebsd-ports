--- lib/avifile/AviSegWrite.cpp.orig	Tue Oct  3 15:44:42 2000
+++ lib/avifile/AviSegWrite.cpp	Sun Dec  7 02:30:26 2003
@@ -1,5 +1,5 @@
 #include "AviSegWrite.h"
-IAviSegWriteFile* CreateSegmentedFile(const char* name, unsigned long flimit=0x7F000000, int flags=0, int mask=00777)
+IAviSegWriteFile* CreateSegmentedFile(const char* name, unsigned long flimit, int flags, int mask)
 {
     return new AviSegWriteFile(name, flimit, flags, mask);
 }
@@ -65,7 +65,7 @@
     return str.vstream;
 }
 IAviAudioWriteStream* AviSegWriteFile::AddAudioStream(int fourcc, 
-	WAVEFORMATEX* fmt, int bitrate, int flags=0)
+	WAVEFORMATEX* fmt, int bitrate, int flags)
 {
     if(!fmt)return 0;
     streaminfo str;
@@ -85,7 +85,7 @@
 IAviWriteStream* AviSegWriteFile::AddStream(enum AviStream::StreamType type,
 	const char* format, Unsigned format_size,
 	int handler, int frame_rate,
-	int samplesize=0, int quality=0, int flags=0)
+	int samplesize, int quality, int flags)
 
 //IAviWriteStream* AviSegWriteFile::AddStream(enum AviStream::StreamType type)
 {
@@ -120,7 +120,7 @@
 {
     if(_format)delete _format;
 }
-AviSegWriteFile::AviSegWriteFile(const char* name, unsigned long flimit=0x7F000000, int flags=0, int mask=00777)
+AviSegWriteFile::AviSegWriteFile(const char* name, unsigned long flimit, int flags, int mask)
     :_name(name), m_lFlimit(flimit), _flags(flags), _mask(mask), _size(0LL)
 {
     rf=new AviWriteFile(name, flags, mask);
@@ -134,7 +134,7 @@
 	    delete it->format;
 }
 
-HRESULT AviSegWriteStream::AddChunk(const char* chunk, Unsigned size, Unsigned flags=0)
+HRESULT AviSegWriteStream::AddChunk(const char* chunk, Unsigned size, Unsigned flags)
 {	
     HRESULT result=m_pStream->AddChunk(chunk, size, flags);
     if(m_pFile->rf->FileSize()>m_pFile->m_lFlimit)
