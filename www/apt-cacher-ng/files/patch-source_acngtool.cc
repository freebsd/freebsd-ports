--- source/acngtool.cc.orig	2018-09-07 13:02:18 UTC
+++ source/acngtool.cc
@@ -562,8 +562,10 @@ int maint_job()
 						if (!ids.send(m_conFd))
 							return;
 
+#ifdef HAVE_SSL
 						m_ssl = nullptr;
 						m_bio = nullptr;
+#endif
 						// better match the TCP socket parameters
 						m_sHostName = "localhost";
 						m_sPort = sDefPortHTTP;
