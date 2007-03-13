--- src/clam.cpp.orig	Sun Oct  1 20:01:37 2006
+++ src/clam.cpp	Tue Feb 20 16:04:03 2007
@@ -78,8 +78,8 @@
       memset(&limits,0,sizeof(struct cl_limits));
       root = NULL;
 
-      if ((err = cl_loaddbdir(cl_retdbdir(), &root, &signo)))
-        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_loaddbdir",err);
+      if ((err = cl_load(cl_retdbdir(), &root, &signo, CL_DB_STDOPT)))
+        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_load",err);
 
       if ((err = cl_build(root)))
         throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_build",err);
@@ -214,7 +214,7 @@
             throw cException(CLAMAV_TASK_NAME,"taskProc","pthread_mutex_lock(dbMutex)",err);
           cl_free(ptr->root);
           ptr->root = NULL;
-          cl_loaddbdir(cl_retdbdir(), &(ptr->root), &signo);
+          cl_load(cl_retdbdir(), &(ptr->root), &signo, CL_DB_STDOPT);
           cl_build(ptr->root);
           if ((err = pthread_mutex_unlock(&(ptr->dbMutex))))
             throw cException(CLAMAV_TASK_NAME,"taskProc","pthread_mutex_unlock(dbMutex)",err,1);
