
$FreeBSD$

--- wrapper/wrapper.cxx
+++ wrapper/wrapper.cxx
@@ -133,10 +133,6 @@
 	{
 		WRAPTRACE(4, "Starting...");
 		PTrace::Initialise(log_lev, log_file);
-#ifdef P_HAS_IPV6
-		if (PIPSocket::IsIpAddressFamilyV6Supported())
-			PIPSocket::SetDefaultIpAddressFamilyV6();
-#endif
 		endPoint = new WrapH323EndPoint(prefixes, prefix_num);
 		//gkServer = new WrapGatekeeperServer((H323EndPoint &)*endPoint);
 		gkServer = NULL;
