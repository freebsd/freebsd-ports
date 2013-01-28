--- ./src/ConnectionHandler.cpp.orig	2012-09-29 17:06:45.000000000 -0300
+++ ./src/ConnectionHandler.cpp	2013-01-16 03:04:07.000000000 -0200
@@ -1488,8 +1488,11 @@
 					
 					//if we cant write the certificate its not the end of the world but it is slow
 					if (!writecert){
+#ifdef DGDEBUG
 						std::cout << dbgPeerPort << " -Couldn't save certificate to on disk cache" << std::endl;
+#endif
 						syslog(LOG_ERR,"Couldn't save certificate to on disk cache");
+
					}
 #ifdef DGDEBUG
	
