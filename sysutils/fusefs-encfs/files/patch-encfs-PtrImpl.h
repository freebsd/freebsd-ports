--- encfs/PtrImpl.h.orig	Fri Apr 15 11:34:22 2005
+++ encfs/PtrImpl.h	Thu Jan 18 22:34:52 2007
@@ -26,6 +26,16 @@
 
 #include "OpaqueValue.h"
 
+#include "config.h"
+#if defined(HAVE_ATOMIC_GCC) || defined(HAVE_ATOMIC_GCC_PRIVATE)
+#include <bits/atomicity.h>
+#define HAVE_ATOMIC_FUNCS
+#endif
+
+#if defined(HAVE_ATOMIC_GCC_PRIVATE)
+using namespace __gnu_cxx;
+#endif
+
 namespace rel
 {
 
@@ -55,7 +65,12 @@
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
