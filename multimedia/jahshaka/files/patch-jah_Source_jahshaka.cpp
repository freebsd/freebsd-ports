--- jah/Source/jahshaka.cpp.orig
+++ jah/Source/jahshaka.cpp
@@ -185,6 +185,8 @@
     QString fileinfo;
     bool    foundpath;
 
+#if !defined(__FreeBSD__)
+
     //this hack gets the application exectuable path
     //since QApplication::applicationFilePath() only works on Qt 3.2 and up
     jtrace.debug("QT_VERSION_STR: ");
@@ -356,6 +358,13 @@
         jtrace.debug( "Didnt find media folder, using default media folder" );
         JahMediaPath = JahBasePath;
     }
+
+#else
+
+    JahBasePath  = "%%DATADIR%%/";
+    JahMediaPath = JahBasePath;
+
+#endif
 
     //update preferences object with info
     jprefs.setBasePath(JahBasePath);
