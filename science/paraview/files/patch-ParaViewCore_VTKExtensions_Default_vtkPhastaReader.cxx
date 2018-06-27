--- ParaViewCore/VTKExtensions/Default/vtkPhastaReader.cxx.orig	2018-06-01 19:23:15 UTC
+++ ParaViewCore/VTKExtensions/Default/vtkPhastaReader.cxx
@@ -200,7 +200,7 @@ int vtkPhastaReader::readHeader(FILE* fi
     {
       text_header = new char[real_length + 1];
       strncpy(text_header, Line, real_length);
-      text_header[real_length] = static_cast<char>(NULL);
+      text_header[real_length] = static_cast<char>(0);
       token = strtok(text_header, ":");
       if (cscompare(phrase, token))
       {
