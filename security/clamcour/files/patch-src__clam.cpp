--- src/clam.cpp.orig	2006-10-01 15:01:37.000000000 -0300
+++ src/clam.cpp	2009-03-25 15:08:59.000000000 -0300
@@ -52,8 +52,7 @@
 #include "clam.h"
 #include "exception.h"
 
-struct cl_node *cClamAv::root;
-struct cl_limits cClamAv::limits;
+struct cl_engine *cClamAv::root;
 int cClamAv::counter = 0;
 int cClamAv::scanTaskCounter = 0;
 pthread_mutex_t cClamAv::counterMutex = PTHREAD_MUTEX_INITIALIZER;
@@ -75,14 +74,16 @@
 
     if (!(counter++))
     {
-      memset(&limits,0,sizeof(struct cl_limits));
-      root = NULL;
+      if ((err = cl_init(CL_INIT_DEFAULT)))
+        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_init",err);
+
+      root = cl_engine_new();
 
-      if ((err = cl_loaddbdir(cl_retdbdir(), &root, &signo)))
-        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_loaddbdir",err);
+      if ((err = cl_load(cl_retdbdir(), root, &signo, CL_DB_STDOPT)))
+        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_load",err);
 
-      if ((err = cl_build(root)))
-        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_build",err);
+      if ((err = cl_engine_compile(root)))
+        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"cl_engine_compile",err);
 
       if ((err = pthread_attr_init(&thattr)))
        throw cException(CLAMAV_CLASS_NAME,CLAMAV_CLASS_NAME,"pthread_attr_init",err,1);
@@ -119,7 +120,7 @@
   {
     pthread_kill(thid,SIGUSR2);
 
-    cl_free(root);
+    cl_engine_free(root);
     root = NULL;
   }
 }
@@ -144,7 +145,6 @@
                                             virus_name,
                                             NULL,
                                             root,
-                                            &limits,
                                             CL_SCAN_ARCHIVE|CL_SCAN_MAIL|CL_SCAN_OLE2|CL_SCAN_PE|
                                             CL_SCAN_HTML|CL_SCAN_BLOCKBROKEN) : CL_CLEAN);
     else
@@ -212,10 +212,10 @@
         {
           if ((err = pthread_mutex_lock(&(ptr->dbMutex))))
             throw cException(CLAMAV_TASK_NAME,"taskProc","pthread_mutex_lock(dbMutex)",err);
-          cl_free(ptr->root);
+          cl_engine_free(ptr->root);
           ptr->root = NULL;
-          cl_loaddbdir(cl_retdbdir(), &(ptr->root), &signo);
-          cl_build(ptr->root);
+          cl_load(cl_retdbdir(), ptr->root, &signo, CL_DB_STDOPT);
+          cl_engine_compile(ptr->root);
           if ((err = pthread_mutex_unlock(&(ptr->dbMutex))))
             throw cException(CLAMAV_TASK_NAME,"taskProc","pthread_mutex_unlock(dbMutex)",err,1);
           syslog(LOG_INFO,"cClamDBTask -> database updated");
