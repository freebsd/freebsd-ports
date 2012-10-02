--- content/common/sandbox_seccomp_bpf_linux.cc.orig	2012-10-02 00:12:55.000000000 +0300
+++ content/common/sandbox_seccomp_bpf_linux.cc	2012-10-02 00:13:01.000000000 +0300
@@ -2,15 +2,15 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <asm/unistd.h>
+//#include <asm/unistd.h>
 #include <dlfcn.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <linux/audit.h>
-#include <linux/filter.h>
+//include <linux/audit.h>
+//#include <linux/filter.h>
 #include <signal.h>
 #include <string.h>
-#include <sys/prctl.h>
+//#include <sys/prctl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <ucontext.h>
@@ -25,7 +25,7 @@
 #include "content/public/common/content_switches.h"
 
 // These are the only architectures supported for now.
-#if defined(__i386__) || defined(__x86_64__)
+#if (defined(__i386__) || defined(__x86_64__)) && !defined(OS_FREEBSD)
 #define SECCOMP_BPF_SANDBOX
 #endif
 
