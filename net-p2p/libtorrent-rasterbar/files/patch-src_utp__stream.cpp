--- src/utp_stream.cpp.orig	2014-12-05 01:00:07 UTC
+++ src/utp_stream.cpp
@@ -30,6 +30,8 @@ POSSIBILITY OF SUCH DAMAGE.
 
 */
 
+#define __STDC_LIMIT_MACROS 
+#include <stdint.h>
 #include "libtorrent/config.hpp"
 #include "libtorrent/utp_stream.hpp"
 #include "libtorrent/sliding_average.hpp"
