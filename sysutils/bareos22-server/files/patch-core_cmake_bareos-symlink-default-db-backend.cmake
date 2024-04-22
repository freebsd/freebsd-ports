--- core/cmake/bareos-symlink-default-db-backend.cmake.orig	2020-12-11 13:44:43 UTC
+++ core/cmake/bareos-symlink-default-db-backend.cmake
@@ -16,13 +16,31 @@
 #   along with this program; if not, write to the Free Software
 #   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 #   02110-1301, USA.
+
+# The ${libdir} and ${backenddir} are absolute, so figure out
+# a relative path (${backenddir} lives under ${libdir}) instead.
+# Make the link relative, placing the libbareoscats.so in ${libdir}.
+# Within this script, VERSION is set to BAREOS_NUMERIC_VERSION (see
+# core/src/cats/CMakeLists.txt).
 message(
   STATUS
     "${CMAKE_COMMAND} -E create_symlink ${libdir}/libbareoscats${CMAKE_SHARED_LIBRARY_SUFFIX} ${backenddir}/libbareoscats-${default_db_backend}${CMAKE_SHARED_LIBRARY_SUFFIX}"
 )
+file(
+  RELATIVE_PATH 
+    _rel 
+    ${libdir} 
+    ${backenddir}/libbareoscats-${default_db_backend}${CMAKE_SHARED_LIBRARY_SUFFIX}
+)
+message(
+  STATUS 
+    ".. actually ${_rel} in $ENV{DESTDIR} v ${VERSION}"
+)
+
 execute_process(
   COMMAND
     ${CMAKE_COMMAND} -E create_symlink
-    ${backenddir}/libbareoscats-${default_db_backend}${CMAKE_SHARED_LIBRARY_SUFFIX}
-    ${libdir}/libbareoscats${CMAKE_SHARED_LIBRARY_SUFFIX}.${BAREOS_NUMERIC_VERSION}
+    ${_rel}
+    libbareoscats${CMAKE_SHARED_LIBRARY_SUFFIX}.${VERSION}
+    WORKING_DIRECTORY $ENV{DESTDIR}${libdir} COMMAND_ECHO STDOUT
 )
