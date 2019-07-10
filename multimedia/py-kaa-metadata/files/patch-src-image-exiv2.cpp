--- src/image/exiv2.cpp.orig	2009-01-30 21:18:25 UTC
+++ src/image/exiv2.cpp
@@ -1,6 +1,5 @@
 #include <Python.h>
-#include <exiv2/image.hpp>
-#include <exiv2/exif.hpp>
+#include <exiv2/exiv2.hpp>
 
 PyObject *parse(PyObject *self, PyObject *args)
 {
@@ -47,7 +46,8 @@ PyObject *parse(PyObject *self, PyObject *args)
 		Py_DECREF(entry);
 	    }
 
-	    Exiv2::DataBuf databuf = exifData.copyThumbnail();
+	    Exiv2::ExifThumbC ExifThumb(exifData);
+	    Exiv2::DataBuf databuf = ExifThumb.copy();
 	    if (databuf.pData_) {
 		entry = PyBuffer_New(databuf.size_);
 		PyObject_AsWriteBuffer(entry, (void **)&data, &len);
