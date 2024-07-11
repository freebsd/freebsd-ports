Backport upstream fixes for taglib 2.x support and remove usages of member
functions that were deprecated in taglib 1.x and removed in 2.x.

Obtained from:
https://code.videolan.org/videolan/vlc/-/commit/d2663d6c3fe3af76bdefd58367b4a45c598b83e4
https://code.videolan.org/videolan/vlc/-/commit/ac59d0ba59ba800c52c0a92ec1d9576d2653dbe2
https://code.videolan.org/videolan/vlc/-/commit/c404fdb24183031a419667639846edddca3401f8
https://code.videolan.org/videolan/vlc/-/commit/ec29dfca1e59530dd412d779e0b045079b72ffb6

--- modules/meta_engine/taglib.cpp.orig	2023-04-22 23:27:28 UTC
+++ modules/meta_engine/taglib.cpp
@@ -125,7 +125,11 @@ File *VLCTagLib::ExtResolver<T>::createFile(FileName f
 template <class T>
 File *VLCTagLib::ExtResolver<T>::createFile(FileName fileName, bool, AudioProperties::ReadStyle) const
 {
+#if defined(_WIN32) && TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    std::string filename = fileName.toString().to8Bit(true);
+#else
     std::string filename = std::string(fileName);
+#endif
     std::size_t namesize = filename.size();
 
     if (namesize > ext.length())
@@ -180,12 +184,16 @@ class VlcIostream : public IOStream (public)
         return m_stream->psz_location;
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    ByteVector readBlock(size_t length)
+#else
     ByteVector readBlock(ulong length)
+#endif
     {
         ByteVector res(length, 0);
         ssize_t i_read = vlc_stream_Read( m_stream, res.data(), length);
         if (i_read < 0)
-            return ByteVector::null;
+            return {};
         else if ((size_t)i_read != length)
             res.resize(i_read);
         return res;
@@ -196,11 +204,19 @@ class VlcIostream : public IOStream (public)
         // Let's stay Read-Only for now
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    void insert(const ByteVector&, offset_t, size_t)
+#else
     void insert(const ByteVector&, ulong, ulong)
+#endif
     {
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    void removeBlock(offset_t, size_t)
+#else
     void removeBlock(ulong, ulong)
+#endif
     {
     }
 
@@ -214,7 +230,11 @@ class VlcIostream : public IOStream (public)
         return true;
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    void seek(offset_t offset, Position p)
+#else
     void seek(long offset, Position p)
+#endif
     {
         uint64_t pos = 0;
         switch (p)
@@ -237,12 +257,20 @@ class VlcIostream : public IOStream (public)
         return;
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    offset_t tell() const
+#else
     long tell() const
+#endif
     {
         return m_previousPos;
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    offset_t length()
+#else
     long length()
+#endif
     {
         uint64_t i_size;
         if (vlc_stream_GetSize( m_stream, &i_size ) != VLC_SUCCESS)
@@ -250,7 +278,11 @@ class VlcIostream : public IOStream (public)
         return i_size;
     }
 
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+    void truncate(offset_t)
+#else
     void truncate(long)
+#endif
     {
     }
 
@@ -465,7 +497,7 @@ static void ReadMetaFromBasicTag(const Tag* tag, vlc_m
 static void ReadMetaFromBasicTag(const Tag* tag, vlc_meta_t *dest)
 {
 #define SET( accessor, meta )                                                  \
-    if( !tag->accessor().isNull() && !tag->accessor().isEmpty() )              \
+    if( !tag->accessor().isEmpty() )                                           \
         vlc_meta_Set##meta( dest, tag->accessor().toCString(true) )
 #define SETINT( accessor, meta )                                               \
     if( tag->accessor() )                                                      \
@@ -806,15 +838,15 @@ static void ReadMetaFromMP4( MP4::Tag* tag, demux_meta
 {
     MP4::Item list;
 #define SET( keyName, metaName )                                                             \
-    if( tag->itemListMap().contains(keyName) )                                               \
+    if( tag->contains(keyName) )                                                             \
     {                                                                                        \
-        list = tag->itemListMap()[keyName];                                                  \
+        list = tag->item(keyName);                                                           \
         vlc_meta_Set##metaName( p_meta, list.toStringList().front().toCString( true ) );     \
     }
 #define SET_EXTRA( keyName, metaName )                                                   \
-    if( tag->itemListMap().contains(keyName) )                                  \
+    if( tag->contains(keyName) )                                                     \
     {                                                                                \
-        list = tag->itemListMap()[keyName];                                     \
+        list = tag->item(keyName);                                                   \
         vlc_meta_AddExtra( p_meta, metaName, list.toStringList().front().toCString( true ) ); \
     }
 
@@ -824,9 +856,9 @@ static void ReadMetaFromMP4( MP4::Tag* tag, demux_meta
 #undef SET
 #undef SET_EXTRA
 
-    if( tag->itemListMap().contains("covr") )
+    if( tag->contains("covr") )
     {
-        MP4::CoverArtList list = tag->itemListMap()["covr"].toCoverArtList();
+        MP4::CoverArtList list = tag->item("covr").toCoverArtList();
         const char *psz_format = list[0].format() == MP4::CoverArt::PNG ? "image/png" : "image/jpeg";
 
         msg_Dbg( p_demux_meta, "Found embedded art (%s) is %i bytes",
@@ -1337,7 +1369,11 @@ static int WriteMeta( vlc_object_t *p_this )
         if( RIFF::AIFF::File* riff_aiff = dynamic_cast<RIFF::AIFF::File*>(f.file()) )
             WriteMetaToId3v2( riff_aiff->tag(), p_item );
         else if( RIFF::WAV::File* riff_wav = dynamic_cast<RIFF::WAV::File*>(f.file()) )
+#if TAGLIB_VERSION >= VERSION_INT(2, 0, 0)
+            WriteMetaToId3v2( riff_wav->ID3v2Tag(), p_item );
+#else
             WriteMetaToId3v2( riff_wav->tag(), p_item );
+#endif
     }
     else if( TrueAudio::File* trueaudio = dynamic_cast<TrueAudio::File*>(f.file()) )
     {
