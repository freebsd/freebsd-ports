commit 53e3434e3c3369a63a0095a763f9b606eb379a0b
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    need unistd.h for pid_t on FreeBSD

diff --git third_party/libwebrtc/modules/desktop_capture/desktop_capturer.h third_party/libwebrtc/modules/desktop_capture/desktop_capturer.h
index 9b1efa0bb59c..9e018cb4d49f 100644
--- third_party/libwebrtc/modules/desktop_capture/desktop_capturer.h
+++ third_party/libwebrtc/modules/desktop_capture/desktop_capturer.h
@@ -17,6 +17,10 @@
 #include <string>
 #include <type_traits>
 #include <vector>
+#if defined(__FreeBSD__)
+// for pid_t
+#include <unistd.h>
+#endif
 
 // TODO(alcooper): Update include usage in downstream consumers and then change
 // this to a forward declaration.
