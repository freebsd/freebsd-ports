--- libaegisub/common/cajun/reader.cpp.orig	2014-12-08 00:07:09 UTC
+++ libaegisub/common/cajun/reader.cpp
@@ -9,6 +9,7 @@ Author: Terry Caton
 #include "libaegisub/cajun/reader.h"
 
 #include <boost/interprocess/streams/bufferstream.hpp>
+#include <algorithm> // std::find
 #include <cassert>
 
 /*
