--- src/lazy_bdecode.cpp.orig	2014-04-04 02:51:48.000000000 +0000
+++ src/lazy_bdecode.cpp
@@ -30,6 +30,9 @@ POSSIBILITY OF SUCH DAMAGE.
 
 */
 
+#define __STDC_LIMIT_MACROS
+#include <stdint.h>
+
 #include "libtorrent/config.hpp"
 #include "libtorrent/lazy_entry.hpp"
 #include "libtorrent/escape_string.hpp"
