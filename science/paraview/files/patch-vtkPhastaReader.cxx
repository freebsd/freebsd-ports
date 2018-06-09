--- ParaViewCore/VTKExtensions/Default/vtkPhastaReader.cxx.orig	2018-05-31 00:13:08.178409000 +0700
+++ ParaViewCore/VTKExtensions/Default/vtkPhastaReader.cxx	2018-05-31 18:19:21.545706000 +0700
@@ -200,7 +200,7 @@
     {
       text_header = new char[real_length + 1];
       strncpy(text_header, Line, real_length);
-      text_header[real_length] = static_cast<char>(NULL);
+      text_header[real_length] = static_cast<char>(0);
       token = strtok(text_header, ":");
       if (cscompare(phrase, token))
       {
