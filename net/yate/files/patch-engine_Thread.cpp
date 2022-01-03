--- engine/Thread.cpp.orig	2022-01-03 18:04:16 UTC
+++ engine/Thread.cpp
@@ -525,7 +525,7 @@ int ThreadPrivate::setAffinity(ThreadPrivate* t, const
 #else
     pid_t tid  = -1;
     if (!t)
-	tid = (pid_t)syscall(SYS_gettid);
+	tid = (pid_t)syscall(SYS_getpid);
     else {
 	// there is a race between getting the TID and this call
 	// try to hold off for a while, maybe it will get set
@@ -593,7 +593,7 @@ int ThreadPrivate::getAffinity(ThreadPrivate* t, DataB
 #else
     pid_t tid  = -1;
     if (!t)
-	tid = (pid_t)syscall(SYS_gettid);
+	tid = (pid_t)syscall(SYS_getpid);
     else {
 	// there is a race between getting the TID and this call
 	// try to hold off for a while, maybe it will get set
