--- xbmc/music/tags/TagLibVFSStream.cpp.orig	2024-07-20 12:15:29 UTC
+++ xbmc/music/tags/TagLibVFSStream.cpp
@@ -59,7 +59,7 @@ FileName TagLibVFSStream::name() const
  * Reads a block of size \a length at the current get pointer.
  */
 #if (TAGLIB_MAJOR_VERSION >= 2)
-ByteVector TagLibVFSStream::readBlock(unsigned long length)
+ByteVector TagLibVFSStream::readBlock(size_t length)
 #else
 ByteVector TagLibVFSStream::readBlock(TagLib::ulong length)
 #endif
@@ -282,7 +282,7 @@ bool TagLibVFSStream::isOpen() const
  *
  * \see Position
  */
-void TagLibVFSStream::seek(long offset, Position p)
+void TagLibVFSStream::seek(TagLib::offset_t offset, Position p)
 {
   const long fileLen = length();
   if (m_bIsReadOnly && fileLen > 0)
@@ -340,7 +340,7 @@ void TagLibVFSStream::clear()
 /*!
  * Returns the current offset within the file.
  */
-long TagLibVFSStream::tell() const
+TagLib::offset_t TagLibVFSStream::tell() const
 {
   int64_t pos = m_file.GetPosition();
   if(pos > LONG_MAX)
@@ -352,7 +352,7 @@ long TagLibVFSStream::tell() const
 /*!
  * Returns the length of the file.
  */
-long TagLibVFSStream::length()
+TagLib::offset_t TagLibVFSStream::length()
 {
   return (long)m_file.GetLength();
 }
@@ -360,7 +360,7 @@ long TagLibVFSStream::length()
 /*!
  * Truncates the file to a \a length.
  */
-void TagLibVFSStream::truncate(long length)
+void TagLibVFSStream::truncate(TagLib::offset_t length)
 {
   m_file.Truncate(length);
 }
