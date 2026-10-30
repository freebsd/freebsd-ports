commit e9c859ea5fcb425575a66254bdc783437bfb95bd
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    need signal.h for signal stuff on FreeBSD

diff --git xpcom/base/nsMemoryInfoDumper.cpp xpcom/base/nsMemoryInfoDumper.cpp
index 480e7de2f701..eabb85218130 100644
--- xpcom/base/nsMemoryInfoDumper.cpp
+++ xpcom/base/nsMemoryInfoDumper.cpp
@@ -41,6 +41,9 @@
 
 #if defined(MOZ_SUPPORTS_RT_SIGNALS)
 #  include <fcntl.h>
+#if defined(__FreeBSD__)
+#  include <signal.h>
+#endif
 #  include <sys/types.h>
 #  include <sys/stat.h>
 #endif
