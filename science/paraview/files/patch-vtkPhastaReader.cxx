--- ParaViewCore/VTKExtensions/Default/vtkPhastaReader.cxx.orig	2018-05-27 20:05:20.868911000 +0700
+++ ParaViewCore/VTKExtensions/Default/vtkPhastaReader.cxx	2018-05-27 20:05:16.469487000 +0700
@@ -200,7 +200,7 @@
     {
       text_header = new char[real_length + 1];
       strncpy(text_header, Line, real_length);
-      text_header[real_length] = static_cast<char>(NULL);
+      text_header[real_length] = static_cast<char>(0);
       token = strtok(text_header, ":");
       if (cscompare(phrase, token))
       {
