--- include/libtorrent/bitfield.hpp	2009/04/26 21:21:31	3421
+++ include/libtorrent/bitfield.hpp	2010/05/29 05:46:47	4624
@@ -36,6 +36,7 @@
 #include "libtorrent/assert.hpp"
 #include "libtorrent/config.hpp"
 #include <cstring> // for memset and memcpy
+#include <cstdlib> // for malloc, free and realloc
 
 namespace libtorrent
 {
