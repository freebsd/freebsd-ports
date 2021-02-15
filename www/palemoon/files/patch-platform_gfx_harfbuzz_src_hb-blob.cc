--- platform/gfx/harfbuzz/src/hb-blob.cc.orig	2021-02-05 18:43:01 UTC
+++ platform/gfx/harfbuzz/src/hb-blob.cc
@@ -24,9 +24,11 @@
  * Red Hat Author(s): Behdad Esfahbod
  */
 
+#ifndef __FreeBSD__
 /* http://www.oracle.com/technetwork/articles/servers-storage-dev/standardheaderfiles-453865.html */
 #ifndef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 199309L
+#endif
 #endif
 
 #include "hb-private.hh"
