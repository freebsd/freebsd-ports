--- util/mp4chaps.cpp.orig	2012-05-20 22:11:55 UTC
+++ util/mp4chaps.cpp
@@ -856,6 +856,7 @@ ChapterUtility::readChapterFile( const s
     if( in.read( inBuf, fileSize, nin ) )
     {
         in.close();
+        free(inBuf);
         return herrf( "reading chapter file '%s' failed: %s\n", filename.c_str(), sys::getLastErrorStr() );
     }
     in.close();
