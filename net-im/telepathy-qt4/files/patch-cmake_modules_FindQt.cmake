--- cmake/modules/FindQt.cmake.orig	2013-11-09 10:25:04.481793123 +0000
+++ cmake/modules/FindQt.cmake	2013-11-09 10:25:11.662793204 +0000
@@ -74,7 +74,11 @@
 
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
       QT5_CREATE_MOC_COMMAND(${infile} ${outfile} "${moc_flags}" "${moc_options}")
