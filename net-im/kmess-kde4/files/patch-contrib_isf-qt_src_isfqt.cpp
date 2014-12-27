--- contrib/isf-qt/src/isfqt.cpp.orig	2012-02-18 16:28:01 UTC
+++ contrib/isf-qt/src/isfqt.cpp
@@ -489,7 +489,11 @@ QByteArray Stream::writerGif( const Draw
 
   // Open the gif file
   gifData.open( QIODevice::WriteOnly );
+#if GIFLIB_MAJOR >= 5
+  gifImage = EGifOpen( (void*)&gifData, GifWriteToByteArray, NULL );
+#else
   gifImage = EGifOpen( (void*)&gifData, GifWriteToByteArray );
+#endif
   if( gifImage == 0 )
   {
     qWarning() << "Couldn't initialize gif library!";
@@ -503,7 +507,11 @@ QByteArray Stream::writerGif( const Draw
     numColors = 256;
   }
 
+#if GIFLIB_MAJOR >= 5
+  cmap = GifMakeMapObject( numColors, NULL );
+#else
   cmap = MakeMapObject( numColors, NULL );
+#endif
   if( cmap == 0 && isfImage.numColors() > 1 )
   {
     qWarning() << "Couldn't create map object for gif conversion (colors:" << isfImage.numColors() << ")!";
@@ -576,7 +584,11 @@ QByteArray Stream::writerGif( const Draw
   else
   {
     // Write the extension
+#if GIFLIB_MAJOR >= 5
+    if( EGifPutExtensionLeader( gifImage, COMMENT_EXT_FUNC_CODE ) == GIF_ERROR )
+#else
     if( EGifPutExtensionFirst( gifImage, COMMENT_EXT_FUNC_CODE, MAX_GIF_BYTE, isfData.left( MAX_GIF_BYTE ).data() ) == GIF_ERROR )
+#endif
     {
       qWarning() << "EGifPutExtensionFirst failed!";
       goto writeError;
@@ -590,7 +602,11 @@ QByteArray Stream::writerGif( const Draw
     // Write all the full data blocks
     while( length >= MAX_GIF_BYTE )
     {
+#if GIFLIB_MAJOR >= 5
+      if( EGifPutExtensionBlock( gifImage, MAX_GIF_BYTE, isfData.mid( pos, MAX_GIF_BYTE ).data() ) == GIF_ERROR )
+#else
       if( EGifPutExtensionNext( gifImage, 0, MAX_GIF_BYTE, isfData.mid( pos, MAX_GIF_BYTE ).data() ) == GIF_ERROR )
+#endif
       {
         qWarning() << "EGifPutExtensionNext failed!";
         goto writeError;
@@ -603,7 +619,11 @@ QByteArray Stream::writerGif( const Draw
     // Write the last block
     if( length > 0 )
     {
+#if GIFLIB_MAJOR >= 5
+      if( EGifPutExtensionTrailer( gifImage ) == GIF_ERROR )
+#else
       if( EGifPutExtensionLast( gifImage, 0, length, isfData.mid( pos, MAX_GIF_BYTE ).data() ) == GIF_ERROR )
+#endif
       {
         qWarning() << "EGifPutExtensionLast (n) failed!";
         goto writeError;
@@ -611,7 +631,11 @@ QByteArray Stream::writerGif( const Draw
     }
     else
     {
+#if GIFLIB_MAJOR >= 5
+      if( EGifPutExtensionTrailer( gifImage ) == GIF_ERROR )
+#else
       if( EGifPutExtensionLast( gifImage, 0, 0, 0 ) == GIF_ERROR )
+#endif
       {
         qWarning() << "EGifPutExtensionLast (0) failed!";
         goto writeError;
@@ -624,12 +648,16 @@ QByteArray Stream::writerGif( const Draw
 writeError:
   // Clean up the GIF converter etc
   EGifCloseFile( gifImage );
+#if GIFLIB_MAJOR >= 5
+  GifFreeMapObject( cmap );
+#else
   FreeMapObject( cmap );
+#endif
   gifData.close();
 
   if( gifError )
   {
-    qWarning() << "GIF error code:" << GifLastError();
+    qWarning() << "GIF error";
   }
   else
   {
