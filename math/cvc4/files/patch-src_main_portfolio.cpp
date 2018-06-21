--- src/main/portfolio.cpp.orig	2018-04-22 17:42:48 UTC
+++ src/main/portfolio.cpp
@@ -18,6 +18,9 @@
 #include <boost/bind.hpp>
 #include <boost/thread/condition.hpp>
 #include <boost/exception_ptr.hpp>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 
 #include "base/output.h"
 #include "options/options.h"
@@ -100,7 +103,11 @@ std::pair<int, S> runPortfolio(int numThreads,
       void *stackaddr;
       size_t stacksize;
       pthread_attr_t attr;
+#ifdef __linux__
       pthread_getattr_np(threads[t].native_handle(), &attr);
+#elif __FreeBSD__
+      pthread_attr_get_np(threads[t].native_handle(), &attr);
+#endif
       pthread_attr_getstack(&attr, &stackaddr, &stacksize);
       Chat() << "Created worker thread " << t << " with stack size " << stacksize << std::endl;
     }
