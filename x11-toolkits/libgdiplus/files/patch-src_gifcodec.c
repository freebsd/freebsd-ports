
$FreeBSD$

--- src/gifcodec.c.orig
+++ src/gifcodec.c
@@ -40,9 +40,13 @@
 #include "gifcodec.h"
 
 #ifdef EgifOpen
-/* giflib declares this incorrectly as EgifOpen */
+/* giflib declares this incorrectly as EgifOpen up to 4.1.2
+   GIF_LIB_VERSION is defined up to 4.1.6, and prototype is changed in 5.0,
+   so it is safe to use it as check condition */
+#ifdef GIF_LIB_VERSION
 extern GifFileType *EGifOpen(void *userData, OutputFunc writeFunc);
 #endif
+#endif
 
 /* Data structure used for callback */
 typedef struct
@@ -131,7 +135,11 @@
 
 	if (ExtData) {
 		memcpy(ep->Bytes, ExtData, Len);
+#if GIFLIB_MAJOR >= 5
+		ep->Function = New->ExtensionBlocks[New->ExtensionBlockCount++].Function;
+#else
 		ep->Function = New->Function;
+#endif
 	}
 
 	return (GIF_OK);
@@ -234,7 +242,11 @@
 			}
 
 			case EXTENSION_RECORD_TYPE: {
+#if GIFLIB_MAJOR >= 5
+				if (DGifGetExtension(GifFile, &temp_save.ExtensionBlocks[temp_save.ExtensionBlockCount].Function, &ExtData) == GIF_ERROR) {
+#else
 				if (DGifGetExtension(GifFile, &temp_save.Function, &ExtData) == GIF_ERROR) {
+#endif
 					return (GIF_ERROR);
 				}
 
@@ -247,7 +259,9 @@
 					if (DGifGetExtensionNext(GifFile, &ExtData) == GIF_ERROR) {
 						return (GIF_ERROR);
 					}
+#if GIFLIB_MAJOR < 5
 					temp_save.Function = 0;
+#endif
 				}
 				break;
 			}
@@ -306,9 +320,17 @@
 	loop_counter = FALSE;
 
 	if (from_file) {
+#if GIFLIB_MAJOR >= 5
+		gif = DGifOpen(stream, &gdip_gif_fileinputfunc, NULL);
+#else 
 		gif = DGifOpen(stream, &gdip_gif_fileinputfunc);
+#endif
 	} else {
+#if GIFLIB_MAJOR >= 5
+		gif = DGifOpen (stream, &gdip_gif_inputfunc, NULL);
+#else
 		gif = DGifOpen (stream, &gdip_gif_inputfunc);
+#endif
 	}
 	
 	if (gif == NULL) {
@@ -663,9 +685,17 @@
 	}
 
 	if (from_file) {
+#if GIFLIB_MAJOR >= 5
+		fp = EGifOpenFileName (stream, 0, NULL);
+#else
 		fp = EGifOpenFileName (stream, 0);
+#endif
 	} else {
+#if GIFLIB_MAJOR >= 5
+		fp = EGifOpen (stream, gdip_gif_outputfunc, NULL);
+#else
 		fp = EGifOpen (stream, gdip_gif_outputfunc);
+#endif
 	}
 		
 	if (!fp) {
@@ -704,7 +734,11 @@
 					goto error; 
 				}
 
+#if GIFLIB_MAJOR >= 5
+				cmap = GifMakeMapObject(cmap_size, 0);
+#else
 				cmap = MakeMapObject(cmap_size, 0);
+#endif
 
 				pixbuf = GdipAlloc(pixbuf_size);
 				if (pixbuf == NULL) {
@@ -795,7 +829,11 @@
 				pixbuf = pixbuf_org;
 			} else {
 				cmap_size = 256;
+#if GIFLIB_MAJOR >= 5
+				cmap  = GifMakeMapObject (cmap_size, 0);
+#else
 				cmap  = MakeMapObject (cmap_size, 0);
+#endif
 
 				red = GdipAlloc(pixbuf_size);
 				green = GdipAlloc(pixbuf_size);
@@ -826,13 +864,21 @@
 						v += 4;
 					}
 				}
+#if GIFLIB_MAJOR >= 5
+				if (GifQuantizeBuffer(bitmap_data->width, bitmap_data->height, &cmap_size, 
+#else
 				if (QuantizeBuffer(bitmap_data->width, bitmap_data->height, &cmap_size, 
+#endif
 						red,  green, blue, pixbuf, cmap->Colors) == GIF_ERROR) {
 					goto error;
 				}
 			}
 
+#if GIFLIB_MAJOR >= 5
+			cmap->BitsPerPixel = GifBitSize (cmap_size);
+#else
 			cmap->BitsPerPixel = BitSize (cmap_size);
+#endif
 			cmap->ColorCount = 1 << cmap->BitsPerPixel;
 
 			if ((frame == 0) && (k == 0)) {
@@ -850,8 +896,15 @@
 						Buffer[0] = 1;
 						Buffer[1] = ptr[0];
 						Buffer[2] = ptr[1];
+#if GIFLIB_MAJOR >= 5
+						EGifPutExtensionLeader(fp, APPLICATION_EXT_FUNC_CODE);
+						EGifPutExtensionBlock(fp, 11, "NETSCAPE2.0");
+						EGifPutExtensionBlock(fp, 3, Buffer);
+						EGifPutExtensionTrailer(fp);
+#else
 						EGifPutExtensionFirst(fp, APPLICATION_EXT_FUNC_CODE, 11, "NETSCAPE2.0");
 						EGifPutExtensionLast(fp, APPLICATION_EXT_FUNC_CODE, 3, Buffer);
+#endif
 					}
 				}
 
@@ -903,7 +956,11 @@
 				pixbuf += bitmap_data->width;
 			}
 
+#if GIFLIB_MAJOR >= 5
+			GifFreeMapObject (cmap);
+#else
 			FreeMapObject (cmap);
+#endif
 			if (red != NULL) {
 				GdipFree (red);
 			}
@@ -931,7 +988,11 @@
 
 error:
 	if (cmap != NULL) {
+#if GIFLIB_MAJOR >= 5
+		GifFreeMapObject (cmap);
+#else
 		FreeMapObject (cmap);
+#endif
 	}
 
 	if (red != NULL) {
