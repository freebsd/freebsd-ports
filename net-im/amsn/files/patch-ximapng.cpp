--- utils/TkCximage/src/CxImage/ximapng.cpp.orig	2010-01-29 10:09:27.000000000 +0100
+++ utils/TkCximage/src/CxImage/ximapng.cpp	2012-05-05 13:25:32.000000000 +0200
@@ -15,7 +15,7 @@
 void CxImagePNG::ima_png_error(png_struct *png_ptr, char *message)
 {
 	strcpy(info.szLastError,message);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 ////////////////////////////////////////////////////////////////////////////////
 #if CXIMAGE_SUPPORT_DECODE
@@ -62,7 +62,7 @@
     /* Set error handling if you are using the setjmp/longjmp method (this is
     * the normal method of doing things with libpng).  REQUIRED unless you
     * set up your own error handlers in the png_create_read_struct() earlier. */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		/* Free all of the memory associated with the png_ptr and info_ptr */
 		delete [] row_pointers;
 		png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
@@ -80,7 +80,7 @@
 		head.biWidth = info_ptr->width;
 		head.biHeight= info_ptr->height;
 		info.dwType = CXIMAGE_FORMAT_PNG;
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 
 	/* calculate new number of channels */
@@ -101,7 +101,7 @@
 		break;
 	default:
 		strcpy(info.szLastError,"unknown PNG color type");
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 
 	//find the right pixel depth used for cximage
@@ -111,7 +111,7 @@
 	if (channels >= 3) pixel_depth=24;
 
 	if (!Create(info_ptr->width, info_ptr->height, pixel_depth, CXIMAGE_FORMAT_PNG)){
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 
 	/* get metrics */
@@ -207,7 +207,7 @@
 	}
 
 	// <vho> - handle cancel
-	if (info.nEscape) longjmp(png_ptr->jmpbuf, 1);
+	if (info.nEscape) longjmp(png_jmpbuf(png_ptr), 1);
 
 	// row_bytes is the width x number of channels x (bit-depth / 8)
 	row_pointers = new BYTE[info_ptr->rowbytes + 8];
@@ -230,7 +230,7 @@
 		do	{
 
 			// <vho> - handle cancel
-			if (info.nEscape) longjmp(png_ptr->jmpbuf, 1);
+			if (info.nEscape) longjmp(png_jmpbuf(png_ptr), 1);
 
 #if CXIMAGE_SUPPORT_ALPHA	// <vho>
 			if (AlphaIsValid()) {
@@ -362,7 +362,7 @@
    /* Set error handling.  REQUIRED if you aren't supplying your own
     * error hadnling functions in the png_create_write_struct() call.
     */
-	if (setjmp(png_ptr->jmpbuf)){
+	if (setjmp(png_jmpbuf(png_ptr))){
 		/* If we get here, we had a problem reading the file */
 		if (info_ptr->palette) free(info_ptr->palette);
 		png_destroy_write_struct(&png_ptr,  (png_infopp)&info_ptr);
