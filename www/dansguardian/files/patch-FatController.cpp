--- FatController.cpp.orig	Mon Jul  7 14:59:33 2003
+++ FatController.cpp	Mon Jul  7 14:59:52 2003
@@ -513,7 +513,7 @@
     if (conn) {
         if (report) {
             if (!isDaemonised) {
-                std::cerr << "Error creating connecting to test proxy" << std::endl;
+                std::cerr << "Error creating connection to test proxy" << std::endl;
             }
             syslog(LOG_ERR, "%s","Error creating connection to test proxy");
         }
