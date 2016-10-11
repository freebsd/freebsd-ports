--- plugins/obs-outputs/net-if.h.orig	2016-09-28 11:25:11 UTC
+++ plugins/obs-outputs/net-if.h
@@ -48,6 +48,7 @@
 #      undef ___NET_IF_GNU_SOURCE__
 #      undef _GNU_SOURCE
 #    endif
+#    include <netinet/in.h>
 #  endif
 
 #endif
