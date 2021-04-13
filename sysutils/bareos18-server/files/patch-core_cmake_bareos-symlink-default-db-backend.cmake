--- core/cmake/bareos-symlink-default-db-backend.cmake.orig	2021-04-13 21:34:51 UTC
+++ core/cmake/bareos-symlink-default-db-backend.cmake
@@ -16,8 +16,17 @@
 #   along with this program; if not, write to the Free Software
 #   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 #   02110-1301, USA.
+
 MESSAGE(STATUS "${CMAKE_COMMAND} -E create_symlink ${libdir}/libbareoscats${CMAKE_SHARED_LIBRARY_SUFFIX} ${backenddir}/libbareoscats-${default_db_backend}${CMAKE_SHARED_LIBRARY_SUFFIX}")
+# The ${libdir} and ${backenddir} are absolute, so figure out
+# a relative path (${backenddir} lives under ${libdir}) instead.
+# Make the link relative, placing the libbareoscats.so in ${libdir}.
+# Within this script, VERSION is set to BAREOS_NUMERIC_VERSION (see
+# core/src/cats/CMakeLists.txt).
+file(RELATIVE_PATH _rel ${libdir} ${backenddir}/libbareoscats-${default_db_backend}${CMAKE_SHARED_LIBRARY_SUFFIX})
+MESSAGE(STATUS ".. actually ${_rel} in $ENV{DESTDIR} v ${VERSION}")
 execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
-   ${backenddir}/libbareoscats-${default_db_backend}${CMAKE_SHARED_LIBRARY_SUFFIX}
-   ${libdir}/libbareoscats${CMAKE_SHARED_LIBRARY_SUFFIX}.${BAREOS_NUMERIC_VERSION}
+   ${_rel}
+   libbareoscats${CMAKE_SHARED_LIBRARY_SUFFIX}.${VERSION}
+   WORKING_DIRECTORY $ENV{DESTDIR}${libdir} COMMAND_ECHO STDOUT
    )
