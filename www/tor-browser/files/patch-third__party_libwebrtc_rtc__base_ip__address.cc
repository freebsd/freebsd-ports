commit d1f5a45c1906e9f1e6a51f3b44c52d981bb3958c
Author: Christoph Moench-Tegeder <cmt@burggraben.net>
Date:   Wed Oct 12 19:57:20 2022 +0200

    pull in sys/types.h for u_XXX typedefs on FreeBSD 12
    
    In file included from /wrkdirs/usr/ports/www/firefox/work/firefox-106.0/third_party/libwebrtc/rtc_base/ip_address.cc:20:
    /usr/include/netinet/ip.h:53:2: error: unknown type name 'u_char'; did you mean 'char'?
            u_char  ip_hl:4,                /* header length */

diff --git third_party/libwebrtc/rtc_base/ip_address.cc third_party/libwebrtc/rtc_base/ip_address.cc
index d544b611e149..ef9b742dac5f 100644
--- third_party/libwebrtc/rtc_base/ip_address.cc
+++ third_party/libwebrtc/rtc_base/ip_address.cc
@@ -11,6 +11,8 @@
 #if defined(WEBRTC_POSIX)
 #include <netinet/in.h>
 #include <sys/socket.h>
+/* for u_char/u_short etc on FreeBSD 12 */
+#include <sys/types.h>
 
 #include "absl/strings/string_view.h"
 #ifdef OPENBSD
