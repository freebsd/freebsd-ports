--- lib/avifile/AviWrite.cpp.orig	Fri Dec  1 20:13:53 2000
+++ lib/avifile/AviWrite.cpp	Sun Dec  7 02:30:26 2003
@@ -45,7 +45,7 @@
 IAviWriteStream* AviWriteFile::AddStream(AviStream::StreamType type,
 	const char* format, Unsigned format_size,
 	int handler, int frame_rate,
-	int samplesize=0, int quality=0, int flags=0)
+	int samplesize, int quality, int flags)
 {
     int ckid;
     ckid=MAKEAVICKID((type==AviWriteStream::Video)?cktypeDIBcompressed:cktypeWAVEbytes, m_streams.size());
@@ -73,7 +73,7 @@
     return result;
 }
 IAviAudioWriteStream* AviWriteFile::AddAudioStream(int fourcc, 
-	WAVEFORMATEX* fmt, int bitrate, int flags=0)
+	WAVEFORMATEX* fmt, int bitrate, int flags)
 {
     int ckid;
     ckid=MAKEAVICKID(cktypeWAVEbytes, m_streams.size());
@@ -134,7 +134,7 @@
     m_status=0;
     return;
 }
-void AviWriteFile::AddChunk(offset_t offset, Unsigned size, Unsigned id, Unsigned flags=0)
+void AviWriteFile::AddChunk(offset_t offset, Unsigned size, Unsigned id, Unsigned flags)
 {
 //    m_index=(AVIINDEXENTRY*)realloc(m_index, (m_indsize+1)*sizeof(AVIINDEXENTRY));
     AVIINDEXENTRY entry;
@@ -164,7 +164,7 @@
         enum AviStream::StreamType type,
 	const char* format, Unsigned format_size,
 	int handler, int frame_rate,
-	int samplesize=0, int quality=0, int flags=0)
+	int samplesize, int quality, int flags)
 	
 	:m_file(file), m_ckid(ckid)
 {
@@ -207,7 +207,7 @@
 }
 AviWriteStream::AviWriteStream(AviWriteFile* file, int ckid,
     enum AviStream::StreamType type,
-    int handler, int frame_rate, int flags=0)
+    int handler, int frame_rate, int flags)
 	:m_file(file), m_ckid(ckid), m_format(0)
 {
     m_fd=file->m_fd;
@@ -243,7 +243,7 @@
 }
 
 
-HRESULT AviWriteStream::AddChunk(const char* chunk, Unsigned size, Unsigned flags=0)
+HRESULT AviWriteStream::AddChunk(const char* chunk, Unsigned size, Unsigned flags)
 {
     if((chunk==0) && (size!=0))
     {
@@ -280,7 +280,7 @@
 IAviVideoWriteStream::~IAviVideoWriteStream(){}
 IAviWriteFile::~IAviWriteFile(){}
 
-IAviWriteFile* CreateIAviWriteFile(const char* name, int flags, int mask=00777)
+IAviWriteFile* CreateIAviWriteFile(const char* name, int flags, int mask)
 {
     return new AviWriteFile(name, flags, mask);
 }    
