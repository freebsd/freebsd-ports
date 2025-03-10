--- fast_library.cpp.orig	2024-12-14 12:46:40 UTC
+++ fast_library.cpp
@@ -1094,15 +1094,13 @@ std::string dns_lookup(std::string domain_name) {
 
 std::string dns_lookup(std::string domain_name) {
     try {
-        boost::asio::io_service io_service;
-        boost::asio::ip::tcp::resolver resolver(io_service);
+        boost::asio::io_context io_context;
+        boost::asio::ip::tcp::resolver resolver(io_context);
 
-        boost::asio::ip::tcp::resolver::query query(domain_name, "");
+        auto results = resolver.resolve(domain_name, "");
 
-        for (boost::asio::ip::tcp::resolver::iterator i = resolver.resolve(query);
-             i != boost::asio::ip::tcp::resolver::iterator(); ++i) {
-            boost::asio::ip::tcp::endpoint end = *i;
-            return end.address().to_string();
+        for (const auto& entry : results) {
+            return entry.endpoint().address().to_string();
         }
     } catch (std::exception& e) {
         return "";
@@ -1428,7 +1426,7 @@ bool validate_ipv6_or_ipv4_host(const std::string host
     boost::system::error_code ec;
 
     // Try to build it from string representation
-    boost::asio::ip::address::from_string(host, ec);
+    boost::asio::ip::make_address(host, ec);
 
     // If we failed to parse it
     if (ec) {
@@ -1535,7 +1533,7 @@ bool execute_web_request_secure(std::string address,
             return false;
         }
 
-        auto end_point = resolver.resolve(boost::asio::ip::tcp::resolver::query{ host, port }, ec);
+        auto end_point = resolver.resolve(host, port, ec);
 
         if (ec) {
             logger << log4cpp::Priority::ERROR << "Could not resolve peer address in execute_web_request " << ec;
@@ -1699,11 +1697,11 @@ bool execute_web_request(std::string address,
 
         // Normal boost::asio setup
         // std::string const host = "178.62.227.110";
-        boost::asio::io_service ios;
+        boost::asio::io_context ios;
         boost::asio::ip::tcp::resolver r(ios);
         boost::asio::ip::tcp::socket sock(ios);
 
-        auto end_point = r.resolve(boost::asio::ip::tcp::resolver::query{ host, port }, ec);
+        auto end_point = r.resolve(host, port, ec);
 
         if (ec) {
             error_text = "Could not resolve peer address in execute_web_request " + ec.message();
