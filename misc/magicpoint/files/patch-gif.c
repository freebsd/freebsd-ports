--- image/gif.c.orig	2000-03-07 07:59:56.000000000 +0100
+++ image/gif.c	2012-06-02 09:10:25.000000000 +0200
@@ -19,6 +19,17 @@
 #include <gif_lib.h>
 
 static void
+localPrintGifError(void)
+{
+    char *Err = GifErrorString();
+
+    if (Err != NULL)
+        fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+    else
+        fprintf(stderr, "\nGIF-LIB undefined error %d.\n", GifError());
+}
+
+static void
 tellAboutImage(name, gifp)
 	char *name;
 	GifFileType *gifp;
@@ -87,13 +98,13 @@
 	/* Scan the content of the GIF file and load the image(s) in: */
 	do {
 		if (DGifGetRecordType(GifFile, &RecordType) == GIF_ERROR) {
-			PrintGifError();
+			localPrintGifError();
 			exit(-1);
 		}
 		switch (RecordType) {
 		case IMAGE_DESC_RECORD_TYPE:
 			if (DGifGetImageDesc(GifFile) == GIF_ERROR) {
-				PrintGifError();
+				localPrintGifError();
 				exit(-1);
 			}
 			Row = GifFile->Image.Top; /* Image Position relative to Screen. */
@@ -113,7 +124,7 @@
 							     j += InterlacedJumps[i]) {
 					if (DGifGetLine(GifFile, &ScreenBuffer[j][Col],
 					    Width) == GIF_ERROR) {
-					    PrintGifError();
+					    localPrintGifError();
 					    exit(-1);
 					}
 				}
@@ -122,7 +133,7 @@
 				for (i = 0; i < Height; i++) {
 					if (DGifGetLine(GifFile, &ScreenBuffer[Row++][Col],
 					    Width) == GIF_ERROR) {
-						PrintGifError();
+						localPrintGifError();
 						exit(-1);
 					}
 				}
@@ -131,7 +142,7 @@
 		case EXTENSION_RECORD_TYPE:
 			/* Skip any extension blocks in file: */
 			if (DGifGetExtension(GifFile, &ExtCode, &Extension) == GIF_ERROR) {
-				PrintGifError();
+				localPrintGifError();
 				exit(-1);
 			}
 			/* very adhoc transparency support */
@@ -141,7 +152,7 @@
 			}
 			while (Extension != NULL) {
 				if (DGifGetExtensionNext(GifFile, &Extension) == GIF_ERROR) {
-					PrintGifError();
+					localPrintGifError();
 					exit(-1);
 				}
 			}
@@ -180,7 +191,7 @@
 	}
 
 	if (DGifCloseFile(GifFile) == GIF_ERROR) {
-		PrintGifError();
+		localPrintGifError();
 		exit(-1);
 	}
 
