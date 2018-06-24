--- ../python3/FindPython3Interp.cmake.orig	2018-06-19 06:38:27 UTC
+++ ../python3/FindPython3Interp.cmake
@@ -39,7 +39,7 @@
 # OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 FIND_PROGRAM(PYTHON3_EXECUTABLE
-  NAMES python3.2mu python3.2m python3.2u python3.2 python3.1 python3.0 python3
+  NAMES python${FREEBSD_PYTHON_VER2}
   PATHS
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\3.2\\InstallPath]
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\3.1\\InstallPath]
@@ -47,7 +47,7 @@ FIND_PROGRAM(PYTHON3_EXECUTABLE
   )
 
 FIND_PROGRAM(PYTHON3_DBG_EXECUTABLE
-  NAMES python3.2dmu python3.2dm python3.2du python3.2d python3.1-dbg python3.0-dbg python3-dbg
+  NAMES python${FREEBSD_PYTHON_VER2}-dbg
   PATHS
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\3.2\\InstallPath]
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\3.1\\InstallPath]
