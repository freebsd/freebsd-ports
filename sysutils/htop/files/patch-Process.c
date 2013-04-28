--- Process.c.orig	2013-04-21 03:33:42.000000000 +0800
+++ Process.c	2013-04-21 03:34:27.000000000 +0800
@@ -602,7 +602,7 @@
 bool Process_changePriorityBy(Process* this, size_t delta) {
    return Process_setPriority(this, this->nice + delta);
 }
-
+/*
 IOPriority Process_updateIOPriority(Process* this) {
    IOPriority ioprio = syscall(SYS_ioprio_get, IOPRIO_WHO_PROCESS, this->pid);
    this->ioPriority = ioprio;
@@ -613,7 +613,7 @@
    syscall(SYS_ioprio_set, IOPRIO_WHO_PROCESS, this->pid, ioprio);
    return (Process_updateIOPriority(this) == ioprio);
 }
-
+*/
 /*
 [1] Note that before kernel 2.6.26 a process that has not asked for
 an io priority formally uses "none" as scheduling class, but the
