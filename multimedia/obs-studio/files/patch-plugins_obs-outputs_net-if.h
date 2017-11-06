--- plugins/obs-outputs/net-if.h.orig	2017-10-25 18:45:20 UTC
+++ plugins/obs-outputs/net-if.h
@@ -49,6 +49,7 @@
 #      undef ___NET_IF_GNU_SOURCE__
 #      undef _GNU_SOURCE
 #    endif
+#    include <netinet/in.h>
 #  endif
 
 #endif
