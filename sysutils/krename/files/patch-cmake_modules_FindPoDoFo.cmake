--- cmake/modules/FindPoDoFo.cmake.orig	2022-08-31 21:22:21 UTC
+++ cmake/modules/FindPoDoFo.cmake
@@ -37,10 +37,10 @@ find_path(PoDoFo_INCLUDE_DIRS
 # THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 find_path(PoDoFo_INCLUDE_DIRS
-  NAMES podofo/podofo.h
+  NAMES podofo09/podofo.h
 )
 find_library(PoDoFo_LIBRARIES
-  NAMES libpodofo podofo
+  NAMES libpodofo09 podofo09
 )
 
 include(FindPackageHandleStandardArgs)
@@ -65,9 +65,9 @@ if(PoDoFo_FOUND)
   # header. The fix is in https://sourceforge.net/p/podofo/code/1830/ and will
   # hopefully be released soon with 0.9.6. Note that krename doesn't use
   # OpenSSL in any way.
-  file(STRINGS "${PoDoFo_INCLUDE_DIRS}/podofo/base/podofo_config.h" PoDoFo_MAJOR_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_MAJOR[ \t]+[0-9]+$")
-  file(STRINGS "${PoDoFo_INCLUDE_DIRS}/podofo/base/podofo_config.h" PoDoFo_MINOR_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_MINOR[ \t]+[0-9]+$")
-  file(STRINGS "${PoDoFo_INCLUDE_DIRS}/podofo/base/podofo_config.h" PoDoFo_PATCH_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_PATCH[ \t]+[0-9]+$")
+  file(STRINGS "${PoDoFo_INCLUDE_DIRS}/podofo09/base/podofo_config.h" PoDoFo_MAJOR_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_MAJOR[ \t]+[0-9]+$")
+  file(STRINGS "${PoDoFo_INCLUDE_DIRS}/podofo09/base/podofo_config.h" PoDoFo_MINOR_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_MINOR[ \t]+[0-9]+$")
+  file(STRINGS "${PoDoFo_INCLUDE_DIRS}/podofo09/base/podofo_config.h" PoDoFo_PATCH_VER_LINE REGEX "^#define[ \t]+PODOFO_VERSION_PATCH[ \t]+[0-9]+$")
   string(REGEX REPLACE "^#define[ \t]+PODOFO_VERSION_MAJOR[ \t]+([0-9]+)$" "\\1" PoDoFo_MAJOR_VER "${PoDoFo_MAJOR_VER_LINE}")
   string(REGEX REPLACE "^#define[ \t]+PODOFO_VERSION_MINOR[ \t]+([0-9]+)$" "\\1" PoDoFo_MINOR_VER "${PoDoFo_MINOR_VER_LINE}")
   string(REGEX REPLACE "^#define[ \t]+PODOFO_VERSION_PATCH[ \t]+([0-9]+)$" "\\1" PoDoFo_PATCH_VER "${PoDoFo_PATCH_VER_LINE}")
