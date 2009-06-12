--- ./server/mpm/prefork/prefork.c.orig	2008-05-31 07:58:46.000000000 -0400
+++ ./server/mpm/prefork/prefork.c	2009-06-11 20:10:12.151389121 -0400
@@ -573,19 +573,27 @@
                 apr_int32_t numdesc;
                 const apr_pollfd_t *pdesc;
 
-                /* timeout == -1 == wait forever */
-                status = apr_pollset_poll(pollset, -1, &numdesc, &pdesc);
+                /* check for termination first so we don't sleep for a while in
+                 * poll if already signalled
+                 */
+                if (one_process && shutdown_pending) {
+                    SAFE_ACCEPT(accept_mutex_off());
+                    return;
+                }
+                else if (die_now) {
+                    /* In graceful stop/restart; drop the mutex
+                     * and terminate the child. */
+                    SAFE_ACCEPT(accept_mutex_off());
+                    clean_child_exit(0);
+                }
+                /* timeout == 10 seconds to avoid a hang at graceful restart/stop
+                 * caused by the closing of sockets by the signal handler
+                 */
+                status = apr_pollset_poll(pollset, apr_time_from_sec(10), 
+                                          &numdesc, &pdesc);
                 if (status != APR_SUCCESS) {
-                    if (APR_STATUS_IS_EINTR(status)) {
-                        if (one_process && shutdown_pending) {
-                            return;
-                        }
-                        else if (die_now) {
-                            /* In graceful stop/restart; drop the mutex
-                             * and terminate the child. */
-                            SAFE_ACCEPT(accept_mutex_off());
-                            clean_child_exit(0);
-                        }
+                    if (APR_STATUS_IS_TIMEUP(status) ||
+                        APR_STATUS_IS_EINTR(status)) {
                         continue;
                     }
                     /* Single Unix documents select as returning errnos
