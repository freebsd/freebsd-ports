--- src/util/semaphore.c.orig	Tue Dec 16 04:05:13 2003
+++ src/util/semaphore.c	Mon Dec 29 19:14:47 2003
@@ -644,45 +644,47 @@
 	filename,
 	linenumber);
 #elif SOMEBSD || OSX
-  int cnt;
-
+  { 
+    int cnt;
+    
 #if DEBUG_SEMUPDOWN
-  LOG(LOG_DEBUG,
-      "DEBUG: up on IPC semaphore\n");
+    LOG(LOG_DEBUG,
+	"DEBUG: up on IPC semaphore\n");
 #endif
-  MUTEX_LOCK(&sem->internalLock);
-  FLOCK(sem->fd, LOCK_EX);
-  LSEEK(sem->fd, 0, SEEK_SET);
-  if (sizeof(int) != READ(sem->fd, &cnt, sizeof(int))) {
-    LOG(LOG_WARNING,
-	"WARNING: could not read IPC semaphore count (%s) at %s:%d!\n",
-	STRERROR(errno),
-	__FILE__,
-	__LINE__);
-    MUTEX_UNLOCK(&sem->internalLock);
-    return;
-  }
-  cnt = htonl(ntohl(cnt)+1);
-  LSEEK(sem->fd, 0, SEEK_SET);
-  if (sizeof(int) != write(sem->fd, &cnt, sizeof(int)))
-    LOG(LOG_WARNING,
-	"WARNING: could not write to IPC file %s (%s) at %s:%d\n",
-	sem->filename,
-	STRERROR(errno),
-	__FILE__,
-	__LINE__);
+    MUTEX_LOCK(&sem->internalLock);
+    FLOCK(sem->fd, LOCK_EX);
+    LSEEK(sem->fd, 0, SEEK_SET);
+    if (sizeof(int) != READ(sem->fd, &cnt, sizeof(int))) {
+      LOG(LOG_WARNING,
+	  "WARNING: could not read IPC semaphore count (%s) at %s:%d!\n",
+	  STRERROR(errno),
+	  __FILE__,
+	  __LINE__);
+      MUTEX_UNLOCK(&sem->internalLock);
+      return;
+    }
+    cnt = htonl(ntohl(cnt)+1);
+    LSEEK(sem->fd, 0, SEEK_SET);
+    if (sizeof(int) != write(sem->fd, &cnt, sizeof(int)))
+      LOG(LOG_WARNING,
+	  "WARNING: could not write to IPC file %s (%s) at %s:%d\n",
+	  sem->filename,
+	  STRERROR(errno),
+	  __FILE__,
+	  __LINE__);
 #if DEBUG_SEMUPDOWN
-  else
-    LOG(LOG_DEBUG,
-	"DEBUG: wrote count %d\n",
-	ntohl(cnt));
+    else
+      LOG(LOG_DEBUG,
+	  "DEBUG: wrote count %d\n",
+	  ntohl(cnt));
 #endif
-  FLOCK(sem->fd, LOCK_UN);
-  MUTEX_UNLOCK(&sem->internalLock);
+    FLOCK(sem->fd, LOCK_UN);
+    MUTEX_UNLOCK(&sem->internalLock);
 #if DEBUG_SEMUPDOWN
-  LOG(LOG_DEBUG,
-      "DEBUG: up on IPC semaphore returns\n");
+    LOG(LOG_DEBUG,
+	"DEBUG: up on IPC semaphore returns\n");
 #endif
+  }
 #else
 #endif
 }
@@ -777,53 +779,55 @@
     }
   }
 #elif SOMEBSD || OSX
-  int cnt;
-
+  {
+    int cnt;
+    
+#if DEBUG_SEMUPDOWN
+    LOG(LOG_DEBUG,
+	"DEBUG: down on IPC semaphore\n");
+#endif
+    MUTEX_LOCK(&sem->internalLock);
+    FLOCK(sem->fd, LOCK_EX);
+    cnt = ntohl(0);
+    while (htonl(cnt) == 0) {
+      LSEEK(sem->fd, 0, SEEK_SET);
+      if (sizeof(int) != READ(sem->fd, &cnt, sizeof(int))) {
+	LOG(LOG_WARNING,
+	    "WARNING: could not read IPC semaphore count (%s) at %s:%d!\n",
+	    STRERROR(errno),
+	    __FILE__,
+	    __LINE__);
+	FLOCK(sem->fd, LOCK_UN);
+	MUTEX_UNLOCK(&sem->internalLock);
+	return;
+      }
+      if (htonl(cnt) == 0) {
+	/* busy wait! */
+	FLOCK(sem->fd, LOCK_UN);
+	gnunet_util_sleep(50 * cronMILLIS);
 #if DEBUG_SEMUPDOWN
-  LOG(LOG_DEBUG,
-      "DEBUG: down on IPC semaphore\n");
+	LOG(LOG_DEBUG,
+	    "DEBUG: down on IPC semaphore: busy waiting...\n");
 #endif
-  MUTEX_LOCK(&sem->internalLock);
-  FLOCK(sem->fd, LOCK_EX);
-  cnt = ntohl(0);
-  while (htonl(cnt) == 0) {
+	FLOCK(sem->fd, LOCK_EX);
+      }
+    }
+    
+    cnt = htonl(ntohl(cnt)-1);
     LSEEK(sem->fd, 0, SEEK_SET);
-    if (sizeof(int) != READ(sem->fd, &cnt, sizeof(int))) {
+    if (sizeof(int) != write(sem->fd, &cnt, sizeof(int)))
       LOG(LOG_WARNING,
-	  "WARNING: could not read IPC semaphore count (%s) at %s:%d!\n",
-	  STRERROR(errno),
+	  "WARNING: could not write update to IPC file %s at %s:%d\n",
+	  sem->filename,
 	  __FILE__,
-	  __LINE__);
-      FLOCK(sem->fd, LOCK_UN);
-      MUTEX_UNLOCK(&sem->internalLock);
-      return;
-    }
-    if (htonl(cnt) == 0) {
-      /* busy wait! */
-      FLOCK(sem->fd, LOCK_UN);
-      gnunet_util_sleep(50 * cronMILLIS);
+	  __LINE__); 
+    FLOCK(sem->fd, LOCK_UN);
+    MUTEX_UNLOCK(&sem->internalLock);
 #if DEBUG_SEMUPDOWN
-      LOG(LOG_DEBUG,
-	  "DEBUG: down on IPC semaphore: busy waiting...\n");
+    LOG(LOG_DEBUG,
+	"DEBUG: down on IPC semaphore returns\n");
 #endif
-      FLOCK(sem->fd, LOCK_EX);
-    }
   }
-
-  cnt = htonl(ntohl(cnt)-1);
-  LSEEK(sem->fd, 0, SEEK_SET);
-  if (sizeof(int) != write(sem->fd, &cnt, sizeof(int)))
-    LOG(LOG_WARNING,
-	"WARNING: could not write update to IPC file %s at %s:%d\n",
-	sem->filename,
-	__FILE__,
-	__LINE__); 
-  FLOCK(sem->fd, LOCK_UN);
-  MUTEX_UNLOCK(&sem->internalLock);
-#if DEBUG_SEMUPDOWN
-  LOG(LOG_DEBUG,
-      "DEBUG: down on IPC semaphore returns\n");
-#endif
 #else
 #endif
 }
@@ -888,41 +892,43 @@
 	filename,
 	linenumber);
 #elif SOMEBSD || OSX
-  int cnt;  
-
+  {
+    int cnt;  
+    
 #if DEBUG_SEMUPDOWN
-  LOG(LOG_DEBUG,
-      "DEBUG: destroying IPC semaphore\n");
+    LOG(LOG_DEBUG,
+	"DEBUG: destroying IPC semaphore\n");
 #endif
-  MUTEX_DESTROY(&sem->internalLock);
-  FLOCK(sem->fd, LOCK_EX);
-  LSEEK(sem->fd, sizeof(int), SEEK_SET);
-  if (sizeof(int) == READ(sem->fd, &cnt, sizeof(int))) {
-    cnt = htonl(ntohl(cnt)-1);
+    MUTEX_DESTROY(&sem->internalLock);
+    FLOCK(sem->fd, LOCK_EX);
     LSEEK(sem->fd, sizeof(int), SEEK_SET);
-    if (sizeof(int) != write(sem->fd, &cnt, sizeof(int)))
+    if (sizeof(int) == READ(sem->fd, &cnt, sizeof(int))) {
+      cnt = htonl(ntohl(cnt)-1);
+      LSEEK(sem->fd, sizeof(int), SEEK_SET);
+      if (sizeof(int) != write(sem->fd, &cnt, sizeof(int)))
+	LOG(LOG_WARNING,
+	    "WARNING: could not write to IPC file %s at %s:%d\n",
+	    sem->filename,
+	    __FILE__,
+	    __LINE__);
+      if (ntohl(cnt) == 0) {
+#if DEBUG_SEMUPDOWN
+	LOG(LOG_DEBUG,
+	    "DEBUG: removing IPC file %s -- last using process is done.\n",
+	    sem->filename);
+#endif
+	UNLINK(sem->filename); 
+      }
+    } else 
       LOG(LOG_WARNING,
-	  "WARNING: could not write to IPC file %s at %s:%d\n",
+	  "WARNING: could not read process count of IPC %s at %s:%d\n",
 	  sem->filename,
 	  __FILE__,
 	  __LINE__);
-    if (ntohl(cnt) == 0) {
-#if DEBUG_SEMUPDOWN
-      LOG(LOG_DEBUG,
-	  "DEBUG: removing IPC file %s -- last using process is done.\n",
-	  sem->filename);
-#endif
-      UNLINK(sem->filename); 
-    }
-  } else 
-    LOG(LOG_WARNING,
-	"WARNING: could not read process count of IPC %s at %s:%d\n",
-	sem->filename,
-	__FILE__,
-	__LINE__);
-  FREE(sem->filename);
-  FLOCK(sem->fd, LOCK_UN);
-  CLOSE(sem->fd);
+    FREE(sem->filename);
+    FLOCK(sem->fd, LOCK_UN);
+    CLOSE(sem->fd);
+  }
 #else
 #endif
   FREE(sem);
