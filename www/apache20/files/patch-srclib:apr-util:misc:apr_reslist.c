--- srclib/apr-util/misc/apr_reslist.c.orig	Fri Feb 13 04:52:43 2004
+++ srclib/apr-util/misc/apr_reslist.c	Mon Mar 15 08:21:26 2004
@@ -49,6 +49,7 @@
     int smax; /* soft maximum on the total number of resources */
     int hmax; /* hard maximum on the total number of resources */
     apr_interval_time_t ttl; /* TTL when we have too many resources */
+    apr_interval_time_t timeout; /* Timeout for waiting on resource */
     apr_reslist_constructor constructor;
     apr_reslist_destructor destructor;
     void *params; /* opaque data passed to constructor and destructor calls */
@@ -118,12 +119,9 @@
     res = apr_pcalloc(reslist->pool, sizeof(*res));
 
     rv = reslist->constructor(&res->opaque, reslist->params, reslist->pool);
-    if (rv != APR_SUCCESS) {
-        return rv;
-    }
 
     *ret_res = res;
-    return APR_SUCCESS;
+    return rv;
 }
 
 /**
@@ -132,14 +130,7 @@
  */
 static apr_status_t destroy_resource(apr_reslist_t *reslist, apr_res_t *res)
 {
-    apr_status_t rv;
-
-    rv = reslist->destructor(res->opaque, reslist->params, reslist->pool);
-    if (rv != APR_SUCCESS) {
-        return rv;
-    }
-
-    return APR_SUCCESS;
+    return reslist->destructor(res->opaque, reslist->params, reslist->pool);
 }
 
 static apr_status_t reslist_cleanup(void *data_)
@@ -187,6 +178,7 @@
         /* Create the resource */
         rv = create_resource(reslist, &res);
         if (rv != APR_SUCCESS) {
+            free_container(reslist, res);
             apr_thread_mutex_unlock(reslist->listlock);
             return rv;
         }
@@ -313,7 +305,15 @@
      * a new one, or something becomes free. */
     else while (reslist->ntotal >= reslist->hmax
                 && reslist->nidle <= 0) {
-        apr_thread_cond_wait(reslist->avail, reslist->listlock);
+        if (reslist->timeout) {
+            if ((rv = apr_thread_cond_timedwait(reslist->avail, 
+                reslist->listlock, reslist->timeout)) != APR_SUCCESS) {
+                apr_thread_mutex_unlock(reslist->listlock);
+                return rv;
+            }
+        }
+        else
+            apr_thread_cond_wait(reslist->avail, reslist->listlock);
     }
     /* If we popped out of the loop, first try to see if there
      * are new resources available for immediate use. */
@@ -329,17 +329,13 @@
      * a resource to fill the slot and use it. */
     else {
         rv = create_resource(reslist, &res);
-
-        if (rv != APR_SUCCESS) {
-           apr_thread_mutex_unlock(reslist->listlock);
-           return rv;
+        if (rv == APR_SUCCESS) {
+            reslist->ntotal++;
+            *resource = res->opaque;
         }
-
-        reslist->ntotal++;
-        *resource = res->opaque;
         free_container(reslist, res);
         apr_thread_mutex_unlock(reslist->listlock);
-        return APR_SUCCESS;
+        return rv;
     }
 }
 
@@ -356,6 +352,23 @@
     apr_thread_mutex_unlock(reslist->listlock);
 
     return reslist_maint(reslist);
+}
+
+APU_DECLARE(void) apr_reslist_timeout_set(apr_reslist_t *reslist,
+                                          apr_interval_time_t timeout)
+{
+    reslist->timeout = timeout;
+}
+
+APU_DECLARE(apr_status_t) apr_reslist_invalidate(apr_reslist_t *reslist,
+                                                 void *resource)
+{
+    apr_status_t ret;
+    apr_thread_mutex_lock(reslist->listlock);
+    ret = reslist->destructor(resource, reslist->params, reslist->pool);
+    reslist->ntotal--;
+    apr_thread_mutex_unlock(reslist->listlock);
+    return ret;
 }
 
 #endif  /* APR_HAS_THREADS */

