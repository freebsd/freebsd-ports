--- servers/slapd/backend.c	Mon Oct  6 16:57:29 2003
+++ servers/slapd/backend.c	Sun Oct 19 15:33:56 2003
@@ -244,8 +244,6 @@
 	int i;
 	int rc = 0;
 
-	init_syncrepl();
-
 	if( ! ( nBackendDB > 0 ) ) {
 		/* no databases */
 #ifdef NEW_LOGGING
@@ -377,6 +375,7 @@
 		if ( backendDB[i].syncinfo != NULL ) {
 			syncinfo_t *si = ( syncinfo_t * ) backendDB[i].syncinfo;
 			si->be = &backendDB[i];
+			init_syncrepl(si);
 			ldap_pvt_thread_mutex_lock( &syncrepl_rq.rq_mutex );
 			ldap_pvt_runqueue_insert( &syncrepl_rq, si->interval,
 							do_syncrepl, (void *) backendDB[i].syncinfo );
