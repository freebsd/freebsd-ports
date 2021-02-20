- patch provided by the upstream

--- src/ProcessHandleApplicInterface.cpp.orig	2021-02-17 01:12:32 UTC
+++ src/ProcessHandleApplicInterface.cpp
@@ -17,6 +17,9 @@
 #include "ParallelLibrary.hpp"
 #include "WorkdirHelper.hpp"
 #include <algorithm>
+#ifdef HAVE_SYS_WAIT_H
+#include <sys/wait.h> // for wait process status macros (Posix only)
+#endif
 
 namespace Dakota {
 
