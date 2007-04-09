--- src/os/linux/OsTaskLinux.cpp.orig	Sat Apr  7 21:29:21 2007
+++ src/os/linux/OsTaskLinux.cpp	Sat Apr  7 21:32:30 2007
@@ -321,14 +321,14 @@
 {
    int taskId;
 
-   taskId = (int)pthread_self();
+   taskId = (int)((uintptr_t)pthread_self());
    return OsTaskLinux::getTaskById(taskId);
 }
 
 // Return an Id of the currently executing task
 OsStatus OsTaskLinux::getCurrentTaskId(int &rid)
 {
-   rid = (int)pthread_self();
+   rid = (int)((uintptr_t)pthread_self());
    return OS_SUCCESS;
 }
 
@@ -435,7 +435,7 @@
    
    //if started, return the taskId, otherwise return -1
    if (isStarted())
-      rId = (int)mTaskId;
+      rId = (int)((uintptr_t)mTaskId);
    else
    {
       retVal = OS_TASK_NOT_STARTED;
@@ -510,8 +510,8 @@
    {
       // Enter the thread id into the global name database so that given the
       // thread id we will be able to find the corresponding OsTask object
-      sprintf(idString, "%d", (int)mTaskId);   // convert the id to a string
-      OsUtil::insertKeyValue(TASKID_PREFIX, idString, (int) this);
+      sprintf(idString, "%d", (int)((uintptr_t)mTaskId));   // convert the id to a string
+      OsUtil::insertKeyValue(TASKID_PREFIX, idString, (int) ((uintptr_t)this));
 
       mState = STARTED;
       return TRUE;
@@ -531,10 +531,10 @@
 
    OsSysLog::add(FAC_KERNEL, PRI_DEBUG,
                  "OsTaskLinux::doLinuxTerminateTask, deleting task thread: %x,"
-                 " force = %d", (int)mTaskId, doForce);
+                 " force = %d", (int)((uintptr_t)mTaskId), doForce);
 
    // if there is no low-level task, or entry in the name database, just return
-   if ((mState != UNINITIALIZED) && ((int)mTaskId != 0))
+   if ((mState != UNINITIALIZED) && ((int)((uintptr_t)mTaskId) != 0))
    {
       // DEBUGGING HACK:  Suspend requestor if target is suspended $$$
       while (isSuspended())
@@ -695,10 +695,10 @@
    OsStatus res;
    char     idString[15];
    
-   if ( 0 != (int)mTaskId )
+   if ( 0 != (uintptr_t)mTaskId )
    {
       // Remove the key from the internal task list, before terminating it
-      sprintf(idString, "%d", (int)mTaskId);    // convert the id to a string
+      sprintf(idString, "%d", (int)((uintptr_t)mTaskId));    // convert the id to a string
       res = OsUtil::deleteKeyValue(TASKID_PREFIX, idString);
    }
    else
@@ -710,7 +710,7 @@
    {
       OsSysLog::add(FAC_KERNEL, PRI_ERR, "OsTaskLinux::doLinuxTerminateTask, failed to delete"
                     " mTaskId = 0x%08x, key '%s', returns %d",
-                    (int) mTaskId, idString, res);
+                    (int) ((uintptr_t)mTaskId), idString, res);
    }
    mTaskId = 0;
 
