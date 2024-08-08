--- xbmc/music/tags/TagLibVFSStream.h.orig	2024-06-28 10:37:37 UTC
+++ xbmc/music/tags/TagLibVFSStream.h
@@ -38,7 +38,7 @@ namespace MUSIC_INFO
      * Reads a block of size \a length at the current get pointer.
      */
 #if (TAGLIB_MAJOR_VERSION >= 2)
-    TagLib::ByteVector readBlock(unsigned long length) override;
+    TagLib::ByteVector readBlock(size_t length) override;
 #else
     TagLib::ByteVector readBlock(TagLib::ulong length) override;
 #endif
@@ -99,7 +99,7 @@ namespace MUSIC_INFO
      *
      * \see Position
      */
-    void seek(long offset, TagLib::IOStream::Position p = Beginning) override;
+    void seek(TagLib::offset_t offset, TagLib::IOStream::Position p = Beginning) override;
 
     /*!
      * Reset the end-of-file and error flags on the file.
@@ -109,17 +109,17 @@ namespace MUSIC_INFO
     /*!
      * Returns the current offset within the file.
      */
-    long tell() const override;
+    TagLib::offset_t tell() const override;
 
     /*!
      * Returns the length of the file.
      */
-    long length() override;
+    TagLib::offset_t length() override;
 
     /*!
      * Truncates the file to a \a length.
      */
-    void truncate(long length) override;
+    void truncate(TagLib::offset_t length) override;
 
   protected:
     /*!
