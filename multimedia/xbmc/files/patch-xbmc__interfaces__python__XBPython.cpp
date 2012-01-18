--- ./xbmc/interfaces/python/XBPython.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/interfaces/python/XBPython.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -428,7 +428,7 @@
 #if !(defined(__APPLE__) || defined(_WIN32))
     DllLoaderContainer::UnloadPythonDlls();
 #endif
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     // we can't release it on windows, as this is done in UnloadPythonDlls() for win32 (see above).
     // The implementation for linux needs looking at - UnloadPythonDlls() currently only searches for "python24.dll"
     // The implementation for osx can never unload the python dylib.
