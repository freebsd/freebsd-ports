--- include/libtorrent/config.hpp.orig	2014-12-05 01:00:07 UTC
+++ include/libtorrent/config.hpp
@@ -166,12 +166,6 @@ POSSIBILITY OF SUCH DAMAGE.
 
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
