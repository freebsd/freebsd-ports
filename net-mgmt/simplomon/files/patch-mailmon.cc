--- mailmon.cc.orig	2025-11-03 17:55:52 UTC
+++ mailmon.cc
@@ -246,7 +246,8 @@ CheckResult SMTPChecker::perform()
     msg+=fmt::format("Message-Id: <{}@simplomon.hostname>\r\n", time(nullptr));
     
     //Date: Thu, 28 Dec 2023 14:31:37 +0100 (CET)
-    msg += fmt::format("Date: {:%a, %d %b %Y %H:%M:%S %z (%Z)}\r\n", fmt::localtime(time(0)));
+    time_t now = time(0);
+    msg += fmt::format("Date: {:%a, %d %b %Y %H:%M:%S %z (%Z)}\r\n", *std::localtime(&now));
     msg+="\r\n";
     
     msg+=to_string(time(nullptr))+"\r\n";
