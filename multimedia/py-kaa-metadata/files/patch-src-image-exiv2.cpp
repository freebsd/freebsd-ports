--- src/image/exiv2.cpp.orig	2009-01-30 22:18:25.000000000 +0100
+++ src/image/exiv2.cpp	2011-07-15 15:48:34.000000000 +0200
@@ -47,7 +47,8 @@
 		Py_DECREF(entry);
 	    }
 
-	    Exiv2::DataBuf databuf = exifData.copyThumbnail();
+	    Exiv2::ExifThumbC ExifThumb(exifData);
+	    Exiv2::DataBuf databuf = ExifThumb.copy();
 	    if (databuf.pData_) {
 		entry = PyBuffer_New(databuf.size_);
 		PyObject_AsWriteBuffer(entry, (void **)&data, &len);
