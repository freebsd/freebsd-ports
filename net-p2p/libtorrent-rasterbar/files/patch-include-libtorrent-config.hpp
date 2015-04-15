--- include/libtorrent/config.hpp.orig	2014-08-15 06:51:56 UTC
+++ include/libtorrent/config.hpp
@@ -184,12 +184,6 @@ POSSIBILITY OF SUCH DAMAGE.
 // execinfo.h is available in the MacOS X 10.5 SDK.
 #define TORRENT_USE_EXECINFO MAC_OS_X_VERSION_MIN_REQUIRED >= 1050
 #endif
-#else
-// FreeBSD has a reasonable iconv signature
-// unless we're on glibc
-#ifndef __GLIBC__
-# define TORRENT_ICONV_ARG (const char**)
-#endif
 #endif
 #define TORRENT_HAS_FALLOCATE 0
 #define TORRENT_USE_IFADDRS 1
