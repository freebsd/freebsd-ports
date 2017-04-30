--- base/process/process_iterator_freebsd.cc.orig	2017-04-19 19:06:28 UTC
+++ base/process/process_iterator_freebsd.cc
@@ -10,6 +10,10 @@
 #include <sys/sysctl.h>
 #include <unistd.h>
 
+/* getuid() */
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "base/logging.h"
 #include "base/macros.h"
 #include "base/strings/string_split.h"
@@ -72,19 +76,13 @@ bool ProcessIterator::CheckForNextProces
   for (; index_of_kinfo_proc_ < kinfo_procs_.size(); ++index_of_kinfo_proc_) {
     size_t length;
     struct kinfo_proc kinfo = kinfo_procs_[index_of_kinfo_proc_];
-    int mib[] = { CTL_KERN, KERN_PROC_ARGS, kinfo.ki_pid };
+    int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_ARGS, kinfo.ki_pid };
 
     if ((kinfo.ki_pid > 0) && (kinfo.ki_stat == SZOMB))
       continue;
 
-    length = 0;
-    if (sysctl(mib, arraysize(mib), NULL, &length, NULL, 0) < 0) {
-      LOG(ERROR) << "failed to figure out the buffer size for a command line";
-      continue;
-    }
-
-    data.resize(length);
-
+    data.resize(ARG_MAX);
+    length = ARG_MAX;
     if (sysctl(mib, arraysize(mib), &data[0], &length, NULL, 0) < 0) {
       LOG(ERROR) << "failed to fetch a commandline";
       continue;
