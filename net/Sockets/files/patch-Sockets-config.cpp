--- Sockets-config.cpp.orig	2012-12-29 14:24:51.000000000 +0100
+++ Sockets-config.cpp	2012-12-29 14:25:16.000000000 +0100
@@ -29,7 +29,7 @@
 
 // ------------------------------------------------------------------
 static	bool any_set = false;
-static	std::map<std::string, std::string> mmap;
+static	std::map<std::string, std::string> sockets_mmap;
 
 // ------------------------------------------------------------------
 void show_info()
@@ -110,24 +110,24 @@
 */
 void setup_configuration()
 {
-	mmap["openssl"] =     "HAVE_OPENSSL";
-	mmap["ipv6"] =        "ENABLE_IPV6";
-	mmap["sctp"] =        "USE_SCTP";
-	mmap["no_addrinfo"] = "NO_GETADDRINFO";
-	mmap["pool"] =        "ENABLE_POOL";
-	mmap["socks4"] =      "ENABLE_SOCKS4";
-	mmap["resolver"] =    "ENABLE_RESOLVER";
-	mmap["reconnect"] =   "ENABLE_RECONNECT";
-	mmap["detach"] =      "ENABLE_DETACH";
-	mmap["exceptions"] =  "ENABLE_EXCEPTIONS";
-	mmap["xml2"] =        "ENABLE_XML";
+	sockets_mmap["openssl"] =     "HAVE_OPENSSL";
+	sockets_mmap["ipv6"] =        "ENABLE_IPV6";
+	sockets_mmap["sctp"] =        "USE_SCTP";
+	sockets_mmap["no_addrinfo"] = "NO_GETADDRINFO";
+	sockets_mmap["pool"] =        "ENABLE_POOL";
+	sockets_mmap["socks4"] =      "ENABLE_SOCKS4";
+	sockets_mmap["resolver"] =    "ENABLE_RESOLVER";
+	sockets_mmap["reconnect"] =   "ENABLE_RECONNECT";
+	sockets_mmap["detach"] =      "ENABLE_DETACH";
+	sockets_mmap["exceptions"] =  "ENABLE_EXCEPTIONS";
+	sockets_mmap["xml2"] =        "ENABLE_XML";
 }
 
 // ------------------------------------------------------------------
 void set(const char *param, bool enable)
 {
-	std::map<std::string, std::string>::iterator it = mmap.find(param);
-	if (it == mmap.end())
+	std::map<std::string, std::string>::iterator it = sockets_mmap.find(param);
+	if (it == sockets_mmap.end())
 	{
 		fprintf(stderr, "Option '%s' not found, aborting\n", param);
 		exit(-1);
@@ -195,7 +195,7 @@
 		{
 			int i = (*slask == '#') ? 8 : 10;
 			std::string def(&slask[i]);
-			for (std::map<std::string, std::string>::iterator it = mmap.begin(); it != mmap.end(); it++)
+			for (std::map<std::string, std::string>::iterator it = sockets_mmap.begin(); it != sockets_mmap.end(); it++)
 			{
 				if (def == it -> second)
 				{
