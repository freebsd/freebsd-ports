--- servers/lloadd/libevent_support.c.orig	2023-02-08 18:49:18 UTC
+++ servers/lloadd/libevent_support.c
@@ -131,6 +131,20 @@ lload_libevent_cond_timedwait(
     return ldap_pvt_thread_cond_wait( cond, mutex );
 }
 
+/*
+ * libevent2 expects the thread id has a type of unsigned long.
+ */
+static unsigned long
+lload_libevent_thread_self(void)
+{
+	unsigned long retval;
+	static_assert(sizeof(ldap_pvt_thread_t) <= sizeof(unsigned long),
+		"ldap_pvt_thread_t has to be smaller or equal to unsigned long");
+
+	retval = (unsigned long)ldap_pvt_thread_self();
+	return (retval);
+}
+
 int
 lload_libevent_init( void )
 {
@@ -160,7 +174,7 @@ lload_libevent_init( void )
 
     evthread_set_lock_callbacks( &cbs );
     evthread_set_condition_callbacks( &cond_cbs );
-    evthread_set_id_callback( ldap_pvt_thread_self );
+    evthread_set_id_callback( lload_libevent_thread_self );
     return 0;
 }
 
