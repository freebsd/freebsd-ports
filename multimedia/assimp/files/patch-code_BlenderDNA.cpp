--- code/BlenderDNA.cpp.orig	2017-02-05 09:22:26 UTC
+++ code/BlenderDNA.cpp
@@ -55,10 +55,10 @@ using namespace Assimp::Formatter;
 
 bool match4(StreamReaderAny& stream, const char* string) {
     char tmp[] = {
-        (stream).GetI1(),
-        (stream).GetI1(),
-        (stream).GetI1(),
-        (stream).GetI1()
+        static_cast<char>((stream).GetI1()),
+        static_cast<char>((stream).GetI1()),
+        static_cast<char>((stream).GetI1()),
+        static_cast<char>((stream).GetI1())
     };
     return (tmp[0]==string[0] && tmp[1]==string[1] && tmp[2]==string[2] && tmp[3]==string[3]);
 }
@@ -345,10 +345,10 @@ void SectionParser :: Next()
     stream.SetCurrentPos(current.start + current.size);
 
     const char tmp[] = {
-        stream.GetI1(),
-        stream.GetI1(),
-        stream.GetI1(),
-        stream.GetI1()
+        static_cast<char>(stream.GetI1()),
+        static_cast<char>(stream.GetI1()),
+        static_cast<char>(stream.GetI1()),
+        static_cast<char>(stream.GetI1())
     };
     current.id = std::string(tmp,tmp[3]?4:tmp[2]?3:tmp[1]?2:1);
 
