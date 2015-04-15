--- libtorrent/include/libtorrent/config.hpp.orig	2015-03-29 22:58:17 UTC
+++ libtorrent/include/libtorrent/config.hpp
@@ -204,12 +204,6 @@ POSSIBILITY OF SUCH DAMAGE.
 
 #endif // __APPLE__
 
-#else
-// FreeBSD has a reasonable iconv signature
-// unless we're on glibc
-#ifndef __GLIBC__
-# define TORRENT_ICONV_ARG (const char**)
-#endif
 #endif
 #define TORRENT_HAS_FALLOCATE 0
 #define TORRENT_USE_IFADDRS 1
