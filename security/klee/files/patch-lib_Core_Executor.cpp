--- lib/Core/Executor.cpp.orig	2018-07-22 16:43:34 UTC
+++ lib/Core/Executor.cpp
@@ -3885,7 +3885,7 @@ void Executor::prepareForEarlyExit() {
 
 /// Returns the errno location in memory
 int *Executor::getErrnoLocation(const ExecutionState &state) const {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   /* From /usr/include/errno.h: it [errno] is a per-thread variable. */
   return __errno_location();
 #else
