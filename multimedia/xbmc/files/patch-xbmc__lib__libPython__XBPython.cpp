--- xbmc/lib/libPython/XBPython.cpp.orig	2010-12-17 07:17:41.000000000 +0100
+++ xbmc/lib/libPython/XBPython.cpp	2011-03-07 15:00:17.000000000 +0100
@@ -24,7 +24,9 @@
   #include "config.h"
 #endif
 #if (defined USE_EXTERNAL_PYTHON)
-  #if (defined HAVE_LIBPYTHON2_6)
+  #if (defined HAVE_LIBPYTHON2_7)
+    #include <python2.7/Python.h>
+  #elif (defined HAVE_LIBPYTHON2_6)
     #include <python2.6/Python.h>
   #elif (defined HAVE_LIBPYTHON2_5)
     #include <python2.5/Python.h>
@@ -60,6 +62,28 @@
 #else
 #define PYTHON_DLL "special://xbmcbin/system/python/python24-x86-osx.so"
 #endif
+#elif defined(__FreeBSD__)
+#if defined(__x86_64__)
+#if defined(HAVE_LIBPYTHON2_7)
+#define PYTHON_DLL "special://xbmcbin/system/python/python27-x86_64-freebsd.so"
+#elif defined(HAVE_LIBPYTHON2_6)
+#define PYTHON_DLL "special://xbmcbin/system/python/python26-x86_64-freebsd.so"
+#elif defined(HAVE_LIBPYTHON2_5)
+#define PYTHON_DLL "special://xbmcbin/system/python/python25-x86_64-freebsd.so"
+#else /* LIBPYTHON2_4 */
+#define PYTHON_DLL "special://xbmcbin/system/python/python24-x86_64-freebsd.so"
+#endif
+#else /* !__x86_64__ */
+#if defined(HAVE_LIBPYTHON2_7)
+#define PYTHON_DLL "special://xbmcbin/system/python/python27-x86-freebsd.so"
+#elif defined(HAVE_LIBPYTHON2_6)
+#define PYTHON_DLL "special://xbmcbin/system/python/python26-x86-freebsd.so"
+#elif defined(HAVE_LIBPYTHON2_5)
+#define PYTHON_DLL "special://xbmcbin/system/python/python25-x86-freebsd.so"
+#else /* LIBPYTHON2_4 */
+#define PYTHON_DLL "special://xbmcbin/system/python/python24-x86-freebsd.so"
+#endif
+#endif /* __x86_64__ */
 #elif defined(__x86_64__)
 #if (defined HAVE_LIBPYTHON2_6)
 #define PYTHON_DLL "special://xbmcbin/system/python/python26-x86_64-linux.so"
@@ -443,7 +467,7 @@
 
     // first free all dlls loaded by python, after that python24.dll (this is done by UnloadPythonDlls
     DllLoaderContainer::UnloadPythonDlls();
-#ifdef _LINUX
+#if defined(_LINUX) && !defined(__FreeBSD__)
     // we can't release it on windows, as this is done in UnloadPythonDlls() for win32 (see above).
     // The implementation for linux and os x needs looking at - UnloadPythonDlls() currently only searches for "python24.dll"
     DllLoaderContainer::ReleaseModule(m_pDll);
