--- src/3rdparty/chromium/base/process/process_iterator_freebsd.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/process/process_iterator_freebsd.cc
@@ -10,6 +10,10 @@
 #include <sys/sysctl.h>
 #include <unistd.h>
 
+/* getuid() */
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "base/logging.h"
 #include "base/stl_util.h"
 #include "base/strings/string_split.h"
@@ -40,7 +44,7 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
       num_of_kinfo_proc += 16;
       kinfo_procs_.resize(num_of_kinfo_proc);
       len = num_of_kinfo_proc * sizeof(struct kinfo_proc);
-      if (sysctl(mib, base::size(mib), &kinfo_procs_[0], &len, NULL, 0) < 0) {
+      if (sysctl(mib, base::size(mib), kinfo_procs_.data(), &len, NULL, 0) < 0) {
         // If we get a mem error, it just means we need a bigger buffer, so
         // loop around again.  Anything else is a real error and give up.
         if (errno != ENOMEM) {
@@ -72,18 +76,13 @@ bool ProcessIterator::CheckForNextProcess() {
   for (; index_of_kinfo_proc_ < kinfo_procs_.size(); ++index_of_kinfo_proc_) {
     size_t length;
     struct kinfo_proc kinfo = kinfo_procs_[index_of_kinfo_proc_];
-    int mib[] = { CTL_KERN, KERN_PROC_ARGS, kinfo.ki_pid };
+    int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_ARGS, kinfo.ki_pid };
 
     if ((kinfo.ki_pid > 0) && (kinfo.ki_stat == SZOMB))
       continue;
 
-    length = 0;
-    if (sysctl(mib, base::size(mib), NULL, &length, NULL, 0) < 0) {
-      LOG(ERROR) << "failed to figure out the buffer size for a command line";
-      continue;
-    }
-
-    data.resize(length);
+    data.resize(ARG_MAX);
+    length = ARG_MAX;
 
     if (sysctl(mib, base::size(mib), &data[0], &length, NULL, 0) < 0) {
       LOG(ERROR) << "failed to fetch a commandline";
