--- src/lazy_bdecode.cpp.orig	2014-12-05 01:00:07 UTC
+++ src/lazy_bdecode.cpp
@@ -30,6 +30,9 @@ POSSIBILITY OF SUCH DAMAGE.
 
 */
 
+#define __STDC_LIMIT_MACROS
+#include <stdint.h>
+
 #include "libtorrent/config.hpp"
 #include "libtorrent/lazy_entry.hpp"
 #include <cstring>
