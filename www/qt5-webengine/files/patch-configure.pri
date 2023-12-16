* Remove checks for Python2 [1]
* Add support for FreeBSD

[1] Obtained from:

https://gitlab.archlinux.org/archlinux/packaging/packages/qt5-webengine/-/raw/main/qt5-webengine-python3.patch?ref_type=heads

--- configure.pri.orig	2023-07-20 09:52:10 UTC
+++ configure.pri
@@ -7,20 +7,7 @@ defineTest(isPythonVersionSupported) {
 equals(QMAKE_HOST.os, Windows): EXE_SUFFIX = .exe
 
 defineTest(isPythonVersionSupported) {
-    python = $$system_quote($$system_path($$1))
-    python_version = $$system('$$python -c "import sys; print(sys.version_info[0:3])"')
-    python_version ~= s/[()]//g
-    python_version = $$split(python_version, ',')
-    python_major_version = $$first(python_version)
-    greaterThan(python_major_version, 2) {
-        qtLog("Python version 3 is not supported by Chromium.")
-        return(false)
-    }
-    python_minor_version = $$member(python_version, 1)
-    python_patch_version = $$member(python_version, 2)
-    greaterThan(python_major_version, 1): greaterThan(python_minor_version, 6): greaterThan(python_patch_version, 4): return(true)
-    qtLog("Unsupported python version: $${python_major_version}.$${python_minor_version}.$${python_patch_version}.")
-    return(false)
+    return(true)
 }
 
 defineTest(qtConfTest_detectJumboBuild) {
@@ -52,10 +39,10 @@ defineTest(qtConfReport_jumboBuild) {
     qtConfReportPadded($${1}, $$mergeLimit)
 }
 
-defineTest(qtConfTest_detectPython2) {
-    python = $$qtConfFindInPath("python2$$EXE_SUFFIX")
+defineTest(qtConfTest_detectPython) {
+    python = $$qtConfFindInPath("python$$EXE_SUFFIX")
     isEmpty(python) {
-        qtLog("'python2$$EXE_SUFFIX' not found in PATH. Checking for 'python$$EXE_SUFFIX'.")
+        qtLog("'python$$EXE_SUFFIX' not found in PATH. Checking for 'python$$EXE_SUFFIX'.")
         python = $$qtConfFindInPath("python$$EXE_SUFFIX")
     }
     isEmpty(python) {
@@ -63,11 +50,11 @@ defineTest(qtConfTest_detectPython2) {
         return(false)
     }
     !isPythonVersionSupported($$python) {
-        qtLog("A suitable Python 2 executable could not be located.")
+        qtLog("A suitable Python executable could not be located.")
         return(false)
     }
 
-    # Make tests.python2.location available in configure.json.
+    # Make tests.python.location available in configure.json.
     $${1}.location = $$clean_path($$python)
     export($${1}.location)
     $${1}.cache += location
@@ -122,6 +109,9 @@ defineTest(qtConfTest_detectPlatform) {
     }
     macos:qtwebengine_isMacOsPlatformSupported() {
         $${1}.platform = "macos"
+    }
+    unix:qtwebengine_isLinuxPlatformSupported() {
+        $${1}.platform = "linux"
     }
     ios:qtwebengine_isMacOsPlatformSupported() {
         $${1}.platform = "ios"
