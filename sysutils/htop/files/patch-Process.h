--- Process.h.orig	2013-04-21 03:34:39.000000000 +0800
+++ Process.h	2013-04-21 03:34:49.000000000 +0800
@@ -179,11 +179,11 @@
 bool Process_setPriority(Process* this, int priority);
 
 bool Process_changePriorityBy(Process* this, size_t delta);
-
+/*
 IOPriority Process_updateIOPriority(Process* this);
 
 bool Process_setIOPriority(Process* this, IOPriority ioprio);
-
+*/
 /*
 [1] Note that before kernel 2.6.26 a process that has not asked for
 an io priority formally uses "none" as scheduling class, but the
