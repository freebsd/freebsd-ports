--- encfs/PtrImpl.h.orig	Wed Feb 14 22:36:56 2007
+++ encfs/PtrImpl.h	Thu Jun 14 18:04:10 2007
@@ -26,6 +26,20 @@
 
 #include "OpaqueValue.h"
 
+#include "config.h"
+#if defined(HAVE_ATOMIC_GCC) || defined(HAVE_ATOMIC_GCC_PRIVATE)
+#if (__GNUC__ >= 4 && __GNUC_MINOR__ >= 2)
+#include <ext/atomicity.h>
+#else
+#include <bits/atomicity.h>
+#endif
+#define HAVE_ATOMIC_FUNCS
+#endif
+
+#if defined(HAVE_ATOMIC_GCC_PRIVATE)
+using namespace __gnu_cxx;
+#endif
+
 namespace rel
 {
 
@@ -55,7 +69,12 @@
 	virtual void destroy() =0;
 
     protected:
+
+#ifdef HAVE_ATOMIC_FUNCS
+	volatile _Atomic_word refCnt;
+#else
 	int refCnt;
+#endif
     };
     
     /*
