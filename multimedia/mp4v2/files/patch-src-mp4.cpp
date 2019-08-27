--- src/mp4.cpp.orig	2012-05-20 22:11:53 UTC
+++ src/mp4.cpp
@@ -2402,8 +2402,11 @@ MP4FileHandle MP4ReadProvider( const cha
         if (MP4_IS_VALID_FILE_HANDLE(hFile)) {
             MP4File *pFile = (MP4File *)hFile;
             try {
-                return pFile->GetTrackIntegerProperty(trackId,
+                uint32_t bitrate =  pFile->GetTrackIntegerProperty(trackId,
                                                       "mdia.minf.stbl.stsd.*.esds.decConfigDescr.avgBitrate");
+                if( bitrate != 0 ) {
+                    return bitrate;
+                }
             }
             catch( Exception* x ) {
                 //mp4v2::impl::log.errorf(*x);  we don't really need to print this.
