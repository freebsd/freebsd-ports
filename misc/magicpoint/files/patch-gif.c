--- image/gif.c.orig	2000-03-07 06:59:56 UTC
+++ image/gif.c
@@ -15,10 +15,31 @@
 
 #ifdef USE_GIF
 
+#include <stdlib.h>
 #include "image.h"
 #include <gif_lib.h>
 
 static void
+#if GIFLIB_MAJOR >= 5
+localPrintGifError(int ErrorCode)
+#else
+localPrintGifError(void)
+#endif
+{
+#if GIFLIB_MAJOR >= 5
+    char *Err = GifErrorString(ErrorCode);
+#else
+    char *Err = GifErrorString();
+    int ErrorCode = GifError();
+#endif
+
+    if (Err != NULL)
+        fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+    else
+        fprintf(stderr, "\nGIF-LIB undefined error %d.\n", ErrorCode);
+}
+
+static void
 tellAboutImage(name, gifp)
 	char *name;
 	GifFileType *gifp;
@@ -50,7 +71,11 @@ gifLoad(fullname, name, verbose)
 	ColorMapObject *ColorMap;
 	GifColorType *ColorMapEntry;
 
+#if GIFLIB_MAJOR >= 5
+	GifFile = DGifOpenFileName(fullname, NULL);
+#else
 	GifFile = DGifOpenFileName(fullname);
+#endif
 	if (GifFile == NULL)
 		return NULL;
 
@@ -87,13 +112,21 @@ gifLoad(fullname, name, verbose)
 	/* Scan the content of the GIF file and load the image(s) in: */
 	do {
 		if (DGifGetRecordType(GifFile, &RecordType) == GIF_ERROR) {
-			PrintGifError();
+#if GIFLIB_MAJOR >= 5
+			localPrintGifError(GifFile->Error);
+#else
+			localPrintGifError();
+#endif
 			exit(-1);
 		}
 		switch (RecordType) {
 		case IMAGE_DESC_RECORD_TYPE:
 			if (DGifGetImageDesc(GifFile) == GIF_ERROR) {
-				PrintGifError();
+#if GIFLIB_MAJOR >= 5
+				localPrintGifError(GifFile->Error);
+#else
+				localPrintGifError();
+#endif
 				exit(-1);
 			}
 			Row = GifFile->Image.Top; /* Image Position relative to Screen. */
@@ -113,7 +146,11 @@ gifLoad(fullname, name, verbose)
 							     j += InterlacedJumps[i]) {
 					if (DGifGetLine(GifFile, &ScreenBuffer[j][Col],
 					    Width) == GIF_ERROR) {
-					    PrintGifError();
+#if GIFLIB_MAJOR >= 5
+					    localPrintGifError(GifFile->Error);
+#else
+					    localPrintGifError();
+#endif
 					    exit(-1);
 					}
 				}
@@ -122,7 +159,11 @@ gifLoad(fullname, name, verbose)
 				for (i = 0; i < Height; i++) {
 					if (DGifGetLine(GifFile, &ScreenBuffer[Row++][Col],
 					    Width) == GIF_ERROR) {
-						PrintGifError();
+#if GIFLIB_MAJOR >= 5
+						localPrintGifError(GifFile->Error);
+#else
+						localPrintGifError();
+#endif
 						exit(-1);
 					}
 				}
@@ -131,7 +172,11 @@ gifLoad(fullname, name, verbose)
 		case EXTENSION_RECORD_TYPE:
 			/* Skip any extension blocks in file: */
 			if (DGifGetExtension(GifFile, &ExtCode, &Extension) == GIF_ERROR) {
-				PrintGifError();
+#if GIFLIB_MAJOR >= 5
+				localPrintGifError(GifFile->Error);
+#else
+				localPrintGifError();
+#endif
 				exit(-1);
 			}
 			/* very adhoc transparency support */
@@ -141,7 +186,11 @@ gifLoad(fullname, name, verbose)
 			}
 			while (Extension != NULL) {
 				if (DGifGetExtensionNext(GifFile, &Extension) == GIF_ERROR) {
-					PrintGifError();
+#if GIFLIB_MAJOR >= 5
+					localPrintGifError(GifFile->Error);
+#else
+					localPrintGifError();
+#endif
 					exit(-1);
 				}
 			}
@@ -180,7 +229,11 @@ gifLoad(fullname, name, verbose)
 	}
 
 	if (DGifCloseFile(GifFile) == GIF_ERROR) {
-		PrintGifError();
+#if GIFLIB_MAJOR >= 5
+		localPrintGifError(GifFile->Error);
+#else
+		localPrintGifError();
+#endif
 		exit(-1);
 	}
 
@@ -196,7 +249,11 @@ gifIdent(fullname, name)
 	GifFileType *gifp;
 	int ret;
 
+#if GIFLIB_MAJOR >= 5
+	gifp = DGifOpenFileName(fullname, NULL);
+#else
 	gifp = DGifOpenFileName(fullname);
+#endif
 	if (gifp == NULL)
 		ret = 0;
 	else {
