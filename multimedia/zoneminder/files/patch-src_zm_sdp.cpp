--- src/zm_sdp.cpp.orig	2009-05-28 12:45:49.000000000 +0400
+++ src/zm_sdp.cpp	2011-04-08 17:48:07.394806320 +0400
@@ -287,7 +287,7 @@ SessionDescriptor::SessionDescriptor( co
 
 AVFormatContext *SessionDescriptor::generateFormatContext() const
 {
-    AVFormatContext *formatContext = avformat_alloc_context();
+    AVFormatContext *formatContext = av_alloc_format_context();
 
     strncpy( formatContext->filename, mUrl.c_str(), sizeof(formatContext->filename) );
 
