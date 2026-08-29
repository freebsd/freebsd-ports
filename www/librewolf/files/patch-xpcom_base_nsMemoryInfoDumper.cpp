commit adfcac0af36ed1cd49fa035b054a1bdfe11abdba
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    need signal.h for signal stuff on FreeBSD

diff --git xpcom/base/nsMemoryInfoDumper.cpp xpcom/base/nsMemoryInfoDumper.cpp
index 201e214a3c0c..bdb8095048cc 100644
--- xpcom/base/nsMemoryInfoDumper.cpp
+++ xpcom/base/nsMemoryInfoDumper.cpp
@@ -41,6 +41,9 @@
 
 #if defined(MOZ_SUPPORTS_RT_SIGNALS)
 #  include <fcntl.h>
+#if defined(__FreeBSD__)
+#  include <signal.h>
+#endif
 #  include <sys/stat.h>
 #  include <sys/types.h>
 #endif
