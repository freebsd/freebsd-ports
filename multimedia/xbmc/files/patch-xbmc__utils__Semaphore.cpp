--- ./xbmc/utils/Semaphore.cpp.orig	2010-01-22 20:37:53.000000000 +0100
+++ ./xbmc/utils/Semaphore.cpp	2010-12-01 12:17:34.283090420 +0100
@@ -21,7 +21,7 @@
  */
 
 #include "Semaphore.hpp"
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) 
 #include "SemaphorePOSIX.h"
 #elif defined(__APPLE__)
 #include "SemaphoreDarwin.h"
@@ -30,7 +30,7 @@
 CSemaphore::CSemaphore(uint32_t initialCount/*=1*/)
   : ISemaphore()
 {
-#ifdef _SEMAPHORE_H
+#if defined(_SEMAPHORE_H) || defined(_SEMAPHORE_H_)
   m_pSemaphore = new CSemaphorePOSIX(initialCount);
 #elif defined(_BSD_SEMAPHORE_H)
   m_pSemaphore = new CSemaphoreDarwin(initialCount);
@@ -42,7 +42,7 @@
 CSemaphore::CSemaphore(const CSemaphore& sem)
   : ISemaphore()
 {
-#ifdef _SEMAPHORE_H
+#if defined(_SEMAPHORE_H) || defined(_SEMAPHORE_H_)
   m_pSemaphore = new CSemaphorePOSIX(sem.GetCount());
 #elif defined(_BSD_SEMAPHORE_H)
   m_pSemaphore = new CSemaphoreDarwin(sem.GetCount());
