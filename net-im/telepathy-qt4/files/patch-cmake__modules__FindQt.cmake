From 05fe3f4980bbc6b016e25dcf07e44afe29e377c0 Mon Sep 17 00:00:00 2001
From: David Edmundson <kde@davidedmundson.co.uk>
Date: Sun, 29 Sep 2013 22:19:27 +0000
Subject: Fix compilation on new versions of cmake

Recent cmake has changed the argument count to
qt4_create_moc_command, we need to adjust accordingly

Reviewed-by: Dario Freddi <dario.freddi@ispirata.com>
---
diff --git a/cmake/modules/FindQt.cmake b/cmake/modules/FindQt.cmake
index c2eac76..b3131f0 100644
--- cmake/modules/FindQt.cmake
+++ cmake/modules/FindQt.cmake
@@ -74,10 +74,18 @@ ENDMACRO(QT_GET_MOC_FLAGS)
 
 MACRO(QT_CREATE_MOC_COMMAND infile outfile moc_flags moc_options)
   IF(QT_VERSION_MAJOR MATCHES 4)
-    QT4_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}")
+    IF(CMAKE_VERSION VERSION_GREATER 2.8.11.20130607)
+      QT4_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}" "")
+    ELSE(CMAKE_VERSION VERSION_GREATER 2.8.11.20130607)
+      QT4_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}")
+    ENDIF(CMAKE_VERSION VERSION_GREATER 2.8.11.20130607)
   ELSE(QT_VERSION_MAJOR MATCHES 4)
     IF(QT_VERSION_MAJOR MATCHES 5)
-      QT5_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}")
+      IF(CMAKE_VERSION VERSION_GREATER 2.8.11.20130607)
+        QT5_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}" "")
+      ELSE(CMAKE_VERSION VERSION_GREATER 2.8.11.20130607)
+        QT5_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}")
+      ENDIF(CMAKE_VERSION VERSION_GREATER 2.8.11.20130607)
     ENDIF(QT_VERSION_MAJOR MATCHES 5)
   ENDIF(QT_VERSION_MAJOR MATCHES 4)
 ENDMACRO(QT_CREATE_MOC_COMMAND)
--
cgit v0.9.0.2-2-gbebe
