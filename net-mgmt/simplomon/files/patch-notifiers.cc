--- notifiers.cc.orig	2025-11-01 23:43:58 UTC
+++ notifiers.cc
@@ -117,7 +117,8 @@ static void sendAsciiEmailAsync(const std::string& ser
   sc.writen(fmt::format("Message-Id: <{}@simplomon.hostname>\r\n", getRandom64()));
   
   //Date: Thu, 28 Dec 2023 14:31:37 +0100 (CET)
-  sc.writen(fmt::format("Date: {:%a, %d %b %Y %H:%M:%S %z (%Z)}\r\n", fmt::localtime(time(0))));
+  time_t now = time(0);
+  sc.writen(fmt::format("Date: {:%a, %d %b %Y %H:%M:%S %z (%Z)}\r\n", *std::localtime(&now)));
   sc.writen("\r\n");
 
   string withCrlf;
@@ -267,4 +268,3 @@ void TelegramNotifier::alert(const std::string& messag
 
   // fmt::print("{}\n", res->body);
 }
-
