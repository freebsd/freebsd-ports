From 57d131eae6ea57cdfeb63830087df59dff05ebd0 Mon Sep 17 00:00:00 2001
From: Andrey Bodrov <ap.bodrov@gmail.com>
Date: Wed, 26 Aug 2026 17:20:00 +0300
Subject: [PATCH] fix(unix): build on FreeBSD and other non-Linux, non-Apple
 platforms
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

pty_close_inherited_fds() and its SetCloseOnExec() helper are defined
inside `#if defined(__linux__)`, but the call site sits in the `#else`
branch of `#if defined(__APPLE__)` — so it compiles on every non-Apple
platform, not just Linux. macOS and Linux are both fine; anything else
fails to build:

  src/unix/pty.cc:477:7: error: use of undeclared identifier
      'pty_close_inherited_fds'

Compile the same helper on FreeBSD. The Linux implementation is already
portable apart from its close_range() fast path, and FreeBSD has had
close_range(2) with CLOSE_RANGE_CLOEXEC since 13.0, so it is called
directly as a libc function rather than through
syscall(SYS_close_range, ...), which is the Linux-specific spelling. The
fcntl() loop remains the fallback for both platforms, unchanged.

Semantics match Linux exactly: descriptors are marked FD_CLOEXEC, not
closed. closefrom(3) would close them outright, which is not what the
caller expects.

Verified on FreeBSD 15.1 (amd64, node 24.14.1, node-gyp 12.4.0): builds
clean, and spawning /bin/sh through forkpty(3) returns its output with
exit code 0.
---
 src/unix/pty.cc | 11 +++++++++--
 1 file changed, 9 insertions(+), 2 deletions(-)

diff --git a/node_modules/node-pty/src/unix/pty.cc b/node_modules/node-pty/src/unix/pty.cc
index 3b7d3dc1c..ce8f00b9a 100644
--- node_modules/node-pty/src/unix/pty.cc.orig
+++ node_modules/node-pty/src/unix/pty.cc
@@ -112,7 +112,7 @@ struct ExitEvent {
   int exit_code = 0, signal_code = 0;
 };
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 static int
 SetCloseOnExec(int fd) {
@@ -130,8 +130,15 @@ SetCloseOnExec(int fd) {
  */
 static void
 pty_close_inherited_fds() {
+  // FreeBSD 13+ exposes close_range(2) as a plain libc function; Linux
+  // reaches the same syscall through syscall(SYS_close_range, ...).
+  #if defined(__FreeBSD__) && defined(CLOSE_RANGE_CLOEXEC)
+  if (close_range(3, ~0U, CLOSE_RANGE_CLOEXEC) == 0) {
+    return;
+  }
+  #endif
   // Try close_range() first (Linux 5.9+, glibc 2.34+)
-  #if defined(SYS_close_range) && defined(CLOSE_RANGE_CLOEXEC)
+  #if defined(__linux__) && defined(SYS_close_range) && defined(CLOSE_RANGE_CLOEXEC)
   if (syscall(SYS_close_range, 3, ~0U, CLOSE_RANGE_CLOEXEC) == 0) {
     return;
   }
