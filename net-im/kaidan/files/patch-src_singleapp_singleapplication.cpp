Using the default PosixRealtime semaphores causes the application to exit
upon start. SingleApplication is third party to kaidan. This needs more
investigation.

SingleApplication: Unable to create block.
SingleApplication:  QSharedMemory::UnknownError "QSharedMemoryPrivate::initKey:
unable to set key on lock (QSystemSemaphore::handle: unknown error: Invalid argument)"

--- src/singleapp/singleapplication.cpp.orig	2025-02-15 10:18:43 UTC
+++ src/singleapp/singleapplication.cpp
@@ -69,7 +69,7 @@ SingleApplication::SingleApplication(int &argc, char *
     // By explicitly attaching it and then deleting it we make sure that the
     // memory is deleted even after the process has crashed on Unix.
 #if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
-    d->memory = new QSharedMemory(QNativeIpcKey(d->blockServerName));
+    d->memory = new QSharedMemory(QNativeIpcKey(d->blockServerName, QNativeIpcKey::Type::SystemV));
 #else
     d->memory = new QSharedMemory(d->blockServerName);
 #endif
@@ -78,7 +78,7 @@ SingleApplication::SingleApplication(int &argc, char *
 #endif
     // Guarantee thread safe behaviour with a shared memory block.
 #if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
-    d->memory = new QSharedMemory(QNativeIpcKey(d->blockServerName));
+    d->memory = new QSharedMemory(QNativeIpcKey(d->blockServerName, QNativeIpcKey::Type::SystemV));
 #else
     d->memory = new QSharedMemory(d->blockServerName);
 #endif
