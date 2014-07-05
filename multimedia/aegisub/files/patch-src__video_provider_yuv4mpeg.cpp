--- src/video_provider_yuv4mpeg.cpp.orig
+++ src/video_provider_yuv4mpeg.cpp
@@ -47,6 +47,13 @@
 #include <boost/algorithm/string/case_conv.hpp>
 #include <boost/filesystem/path.hpp>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 // All of this cstdio bogus is because of one reason and one reason only:
 // MICROSOFT'S IMPLEMENTATION OF STD::FSTREAM DOES NOT SUPPORT FILES LARGER THAN 2 GB.
 // (yes, really)
@@ -141,7 +148,7 @@
 	int buf;
 
 	if (fseeko(sf, startpos, SEEK_SET))
-		throw VideoOpenError("YUV4MPEG video provider: ReadHeader: failed seeking to position " + std::to_string(startpos));
+		throw VideoOpenError("YUV4MPEG video provider: ReadHeader: failed seeking to position " + TO_STRING(startpos));
 
 	// read header until terminating newline (0x0A) is found
 	while ((buf = fgetc(sf)) != 0x0A) {
@@ -317,7 +324,7 @@
 			seek_table.push_back(curpos);
 			// seek to next frame header start position
 			if (fseeko(sf, frame_sz, SEEK_CUR))
-				throw VideoOpenError("IndexFile: failed seeking to position " + std::to_string(curpos + frame_sz));
+				throw VideoOpenError("IndexFile: failed seeking to position " + TO_STRING(curpos + frame_sz));
 		}
 		else {
 			/// @todo implement rff flags etc
