--- servers/slapd/daemon.c	Mon Oct 13 03:57:02 2003
+++ servers/slapd/daemon.c	Sun Oct 19 15:33:56 2003
@@ -1357,8 +1357,8 @@
 				ldap_pvt_thread_mutex_unlock( &syncrepl_rq.rq_mutex );
 				ldap_pvt_thread_pool_submit( &connection_pool,
 											rtask->routine, (void *) rtask );
+				ldap_pvt_thread_mutex_lock( &syncrepl_rq.rq_mutex );
 			}
-			ldap_pvt_thread_mutex_lock( &syncrepl_rq.rq_mutex );
 			rtask = ldap_pvt_runqueue_next_sched( &syncrepl_rq, &cat );
 		}
 		ldap_pvt_thread_mutex_unlock( &syncrepl_rq.rq_mutex );
@@ -2077,18 +2077,10 @@
 	 * SIGBREAK is generated when a user logs out.
 	 */
 
-#if 0
 #if HAVE_NT_SERVICE_MANAGER && SIGBREAK
 	if (is_NT_Service && sig == SIGBREAK)
-#ifdef NEW_LOGGING
-	    LDAP_LOG( CONNECTION, CRIT,
-		    "slap_sig_shutdown: SIGBREAK ignored.\n", 0, 0, 0 );
-#else
-	    Debug(LDAP_DEBUG_TRACE, "slap_sig_shutdown: SIGBREAK ignored.\n",
-		  0, 0, 0);
-#endif
+		;
 	else
-#endif
 #endif
 #ifdef SIGHUP
 	if (sig == SIGHUP && global_gentlehup && slapd_gentle_shutdown == 0)
