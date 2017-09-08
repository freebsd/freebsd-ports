--- include/libtorrent/config.hpp.orig	2017-07-02 16:18:10 UTC
+++ include/libtorrent/config.hpp
@@ -195,12 +195,6 @@ POSSIBILITY OF SUCH DAMAGE.
 #define TORRENT_USE_EXECINFO 1
 #endif
 
-#else // __APPLE__
-// FreeBSD has a reasonable iconv signature
-// unless we're on glibc
-#ifndef __GLIBC__
-# define TORRENT_ICONV_ARG(x) (x)
-#endif
 #endif // __APPLE__
 
 #define TORRENT_HAVE_MMAP 1
