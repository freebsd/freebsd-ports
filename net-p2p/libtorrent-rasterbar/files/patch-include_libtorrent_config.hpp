--- include/libtorrent/config.hpp.orig	2016-08-23 04:28:09 UTC
+++ include/libtorrent/config.hpp
@@ -180,12 +180,6 @@ POSSIBILITY OF SUCH DAMAGE.
 #define TORRENT_USE_EXECINFO 1
 #endif
 
-#else // __APPLE__
-// FreeBSD has a reasonable iconv signature
-// unless we're on glibc
-#ifndef __GLIBC__
-# define TORRENT_ICONV_ARG (const char**)
-#endif
 #endif // __APPLE__
 
 #define TORRENT_HAVE_MMAP 1
