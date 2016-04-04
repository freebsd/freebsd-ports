--- baselib/session.cpp.orig	2015-09-14 22:48:33 UTC
+++ baselib/session.cpp
@@ -118,7 +118,7 @@ cSession::cSession()
       m_remote_sid( 0 )
 {
     #if GLIB_CHECK_VERSION (2, 32, 0)
-    m_sockets = G_PRIVATE_INIT (g_free);
+    m_sockets = (GPrivate) G_PRIVATE_INIT (g_free);
     #else
     wrap_g_static_private_init( &m_sockets );
     #endif
