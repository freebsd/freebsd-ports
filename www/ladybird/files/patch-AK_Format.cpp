--- AK/Format.cpp.orig	2023-12-17 13:03:11 UTC
+++ AK/Format.cpp
@@ -1215,7 +1215,7 @@ void vdbg(StringView fmtstr, TypeErasedFormatParams& p
             struct timespec ts = {};
             clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
             auto pid = getpid();
-#    ifndef AK_OS_MACOS
+#    if !defined(AK_OS_MACOS) && !defined(AK_OS_FREEBSD)
             // Darwin doesn't handle thread IDs the same way other Unixes do
             auto tid = gettid();
             if (pid == tid)
@@ -1223,7 +1223,7 @@ void vdbg(StringView fmtstr, TypeErasedFormatParams& p
             {
                 builder.appendff("{}.{:03} \033[33;1m{}({})\033[0m: ", ts.tv_sec, ts.tv_nsec / 1000000, process_name, pid);
             }
-#    ifndef AK_OS_MACOS
+#    if !defined(AK_OS_MACOS) && !defined(AK_OS_FREEBSD)
             else {
                 builder.appendff("{}.{:03} \033[33;1m{}({}:{})\033[0m: ", ts.tv_sec, ts.tv_nsec / 1000000, process_name, pid, tid);
             }
