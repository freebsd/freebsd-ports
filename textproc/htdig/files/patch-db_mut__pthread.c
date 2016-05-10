--- db/mut_pthread.c.orig	2002-02-02 18:18:05 UTC
+++ db/mut_pthread.c
@@ -201,7 +201,11 @@ CDB___db_pthread_mutex_lock(mutexp)
 			 * call, and Solaris delivers the signal to the wrong
 			 * LWP.
 			 */
-			if (ret != 0 && ret != ETIME && ret != ETIMEDOUT)
+			if (ret != 0 &&
+#ifndef __FreeBSD__
+			    ret != ETIME &&
+#endif
+			    ret != ETIMEDOUT)
 				return (ret);
 		}
 
