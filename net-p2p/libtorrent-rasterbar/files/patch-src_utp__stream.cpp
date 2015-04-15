--- src/utp_stream.cpp.orig	2013-09-20 12:07:06.000000000 +0000
+++ src/utp_stream.cpp
@@ -30,6 +30,8 @@ POSSIBILITY OF SUCH DAMAGE.
 
 */

+#define __STDC_LIMIT_MACROS 
+#include <stdint.h>
 #include "libtorrent/config.hpp"
 #include "libtorrent/utp_stream.hpp"
 #include "libtorrent/sliding_average.hpp"
