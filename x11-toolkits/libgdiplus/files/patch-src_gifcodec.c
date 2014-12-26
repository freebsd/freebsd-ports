$OpenBSD: patch-src_gifcodec_c,v 1.2 2014/07/18 16:00:28 ajacoutot Exp $

giflib 5.0+
http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/pkgsrc/graphics/libgdiplus/patches/patch-src_gifcodec.c?rev=1.2

--- src/gifcodec.c.orig	Fri Dec  2 18:23:12 2011
+++ src/gifcodec.c	Fri Jul 18 15:30:15 2014
@@ -39,8 +39,12 @@ GUID gdip_gif_image_format_guid = {0xb96b3cb0U, 0x0728
 
 #include "gifcodec.h"
 
-/* giflib declares this incorrectly as EgifOpen */
+/* giflib declares this incorrectly as EgifOpen up to 4.1.2
+   GIF_LIB_VERSION is defined up to 4.1.6, and prototype is changed in 5.0,
+   so it is safe to use it as check condition */
+#ifdef GIF_LIB_VERSION
 extern GifFileType *EGifOpen(void *userData, OutputFunc writeFunc);
+#endif
 
 /* Data structure used for callback */
 typedef struct
@@ -129,7 +133,11 @@ AddExtensionBlockMono(SavedImage *New, int Len, BYTE E
 
 	if (ExtData) {
 		memcpy(ep->Bytes, ExtData, Len);
+#if GIFLIB_MAJOR >= 5
+		ep->Function = New->ExtensionBlocks[New->ExtensionBlockCount++].Function;
+#else
 		ep->Function = New->Function;
+#endif
 	}
 
 	return (GIF_OK);
@@ -232,7 +240,11 @@ DGifSlurpMono(GifFileType * GifFile, SavedImage *Trail
 			}
 
 			case EXTENSION_RECORD_TYPE: {
+#if GIFLIB_MAJOR >= 5
+				if (DGifGetExtension(GifFile, &temp_save.ExtensionBlocks[temp_save.ExtensionBlockCount].Function, &ExtData) == GIF_ERROR) {
+#else
 				if (DGifGetExtension(GifFile, &temp_save.Function, &ExtData) == GIF_ERROR) {
+#endif
 					return (GIF_ERROR);
 				}
 
@@ -245,7 +257,9 @@ DGifSlurpMono(GifFileType * GifFile, SavedImage *Trail
 					if (DGifGetExtensionNext(GifFile, &ExtData) == GIF_ERROR) {
 						return (GIF_ERROR);
 					}
+#if GIFLIB_MAJOR < 5
 					temp_save.Function = 0;
+#endif
 				}
 				break;
 			}
@@ -304,9 +318,17 @@ gdip_load_gif_image (void *stream, GpImage **image, BO
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
@@ -661,9 +683,17 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
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
@@ -702,7 +732,11 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
 					goto error; 
 				}
 
+#if GIFLIB_MAJOR >= 5
+				cmap = GifMakeMapObject(cmap_size, 0);
+#else
 				cmap = MakeMapObject(cmap_size, 0);
+#endif
 
 				pixbuf = GdipAlloc(pixbuf_size);
 				if (pixbuf == NULL) {
@@ -793,7 +827,11 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
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
@@ -824,13 +862,21 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
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
@@ -848,8 +894,15 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
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
 
@@ -901,7 +954,11 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
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
@@ -929,7 +986,11 @@ gdip_save_gif_image (void *stream, GpImage *image, BOO
 
 error:
 	if (cmap != NULL) {
+#if GIFLIB_MAJOR >= 5
+		GifFreeMapObject (cmap);
+#else
 		FreeMapObject (cmap);
+#endif
 	}
 
 	if (red != NULL) {
