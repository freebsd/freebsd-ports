--- libaegisub/common/cajun/reader.cpp.orig
+++ libaegisub/common/cajun/reader.cpp
@@ -10,6 +10,8 @@
 
 #include <boost/interprocess/streams/bufferstream.hpp>
 #include <cassert>
+#include <cstdio>
+#include <set>
 
 /*
 
@@ -231,8 +233,16 @@
 }
 
 void Reader::MatchNumber(std::string& sNumber, InputStream& inputStream) {
+#if defined(_LIBCPP_VERSION)
 	const char numericChars[] = "0123456789.eE-+";
 	while (!inputStream.EOS() && std::find(numericChars, std::end(numericChars), inputStream.Peek()) != std::end(numericChars))
+#else
+	const char sNumericChars[] = "0123456789.eE-+";
+	std::set<char> numericChars; 
+	numericChars.insert(sNumericChars, sNumericChars + sizeof(sNumericChars)); 
+
+	while (!inputStream.EOS()&& numericChars.count(inputStream.Peek())) 
+#endif
 		sNumber.push_back(inputStream.Get());
 }
 
