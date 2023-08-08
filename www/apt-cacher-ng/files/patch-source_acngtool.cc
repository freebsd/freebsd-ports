--- source/acngtool.cc.orig	2020-02-03 18:54:57 UTC
+++ source/acngtool.cc
@@ -579,8 +579,10 @@ struct TUdsFactory : public ::acng::IDlConFactory
 			udsconnection() : tcpconnect(nullptr)
 			{
 				// some static and dummy parameters, and invalidate SSL for sure
+#ifdef HAVE_SSL
 				m_ssl = nullptr;
 				m_bio = nullptr;
+#endif
 				m_sHostName = FAKE_UDS_HOSTNAME;
 				m_sPort = cfg::port;
 
@@ -1006,7 +1008,7 @@ std::unordered_map<string, parm> parms = {
 				}
 			}
 		},
-		{ 
+		{
 			"patch",
 			{
 				3, 3, [](LPCSTR p)
