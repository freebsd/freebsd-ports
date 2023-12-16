--- src/core/core_common.pri.orig	2023-11-09 12:28:27 UTC
+++ src/core/core_common.pri
@@ -15,6 +15,6 @@ CONFIG -= ltcg
 # LTO does not work for Chromium at the moment, so disable it completely for core.
 CONFIG -= ltcg
 
-# Chromium requires C++14
-CONFIG += c++14
+# Chromium requires C++17
+CONFIG += c++1z
 
