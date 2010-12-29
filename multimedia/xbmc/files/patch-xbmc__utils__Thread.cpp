--- ./xbmc/utils/Thread.cpp.orig	2010-05-28 02:51:41.000000000 +0200
+++ ./xbmc/utils/Thread.cpp	2010-12-01 12:17:34.281078203 +0100
@@ -37,7 +37,7 @@
 #include "GraphicContext.h"
 #include "utils/TimeUtils.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 //
 // Use pthread's built-in support for TLS, it's more portable.
 //
@@ -60,7 +60,7 @@
 
 CThread::CThread()
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // Initialize thread local storage and local thread pointer.
   pthread_once(&keyOnce, MakeTlsKeys);
 #endif
@@ -80,7 +80,7 @@
 
 CThread::CThread(IRunnable* pRunnable)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // Initialize thread local storage and local thread pointer.
   pthread_once(&keyOnce, MakeTlsKeys);
 #endif
@@ -111,7 +111,7 @@
 }
 
 #ifdef _LINUX
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 // Use pthread-based TLS.
 #define LOCAL_THREAD ((CThread* )pthread_getspecific(tlsLocalThread))
 #else
@@ -152,7 +152,7 @@
   /* install win32 exception translator */
   win32_exception::install_handler();
 #else
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   pLocalThread = pThread;
 #endif
   struct sigaction action;
@@ -164,7 +164,7 @@
 #endif
 
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // Set the TLS.
   pthread_setspecific(tlsLocalThread, (void*)pThread);
 #endif
