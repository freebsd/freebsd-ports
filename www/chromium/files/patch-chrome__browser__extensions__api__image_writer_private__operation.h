--- chrome/browser/extensions/api/image_writer_private/operation.h.orig	2013-11-08 07:40:50.000000000 +0100
+++ chrome/browser/extensions/api/image_writer_private/operation.h	2013-11-15 20:19:03.000000000 +0100
@@ -107,7 +107,7 @@
   friend class base::RefCountedThreadSafe<Operation>;
 
   // TODO(haven): Clean up these switches. http://crbug.com/292956
-#if defined(OS_LINUX) && !defined(CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(CHROMEOS)
   void WriteRun();
   void WriteChunk(scoped_ptr<image_writer_utils::ImageReader> reader,
                   scoped_ptr<image_writer_utils::ImageWriter> writer,
