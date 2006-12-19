--- programs/mythcommflag/FrameAnalyzer.h~	Thu Aug 17 23:22:25 2006
+++ programs/mythcommflag/FrameAnalyzer.h	Tue Nov 14 15:27:39 2006
@@ -7,6 +7,14 @@
 #ifndef __FRAMEANALYZER_H__
 #define __FRAMEANALYZER_H__
 
+/*
+ * At least FreeBSD doesn't define LONG_LONG_MAX, but it does define
+ * __LONG_LONG_MAX__.  Who knows what other systems do the same?
+ */
+#ifndef LONG_LONG_MAX
+#define LONG_LONG_MAX  __LONG_LONG_MAX__
+#endif
+
 /* Base class for commercial flagging frame analyzers. */
 
 #include <limits.h>
