--- src/exiv2plugin.cpp.orig	2022-08-31 21:22:21 UTC
+++ src/exiv2plugin.cpp
@@ -395,7 +395,7 @@ QString Exiv2Plugin::processFile(BatchRenamer *b, int 
     std::string strFilename(asc.constData(), asc.length());
 
     try {
-        Image::AutoPtr image = Exiv2::ImageFactory::open(strFilename);
+        Image::UniquePtr image = Exiv2::ImageFactory::open(strFilename);
         if (image.get() != nullptr && image->good()) {
             image->readMetadata();
 
