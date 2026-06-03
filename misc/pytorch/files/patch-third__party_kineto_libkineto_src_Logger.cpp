-- Use strerror_r (POSIX) on all non-Windows platforms instead of only Linux.
-- This eliminates the -Werror,-Wunused-private-field warning for errnum_ on FreeBSD.
--- third_party/kineto/libkineto/src/Logger.cpp.orig	2026-05-16 06:01:04 UTC
+++ third_party/kineto/libkineto/src/Logger.cpp
@@ -61,7 +61,7 @@ Logger::~Logger() {
 }
 
 Logger::~Logger() {
-#ifdef __linux__
+#ifndef _WIN32
   if (errnum_ != 0) {
     thread_local char buf[1024];
     buf_ << " : " << strerror_r(errnum_, buf, sizeof(buf));
