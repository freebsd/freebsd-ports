--- ./src/OptionContainer.cpp.orig	2013-01-25 02:31:02.000000000 +0000
+++ ./src/OptionContainer.cpp	2013-01-25 02:31:25.000000000 +0000
@@ -612,7 +612,7 @@
 		}
 
 		// if the more than one port is being used, validate the combination of auth plugins
-		if (authplugins.size() > 1) {
+		if (authplugins.size() > 1 and filter_ports.size() > 1) {
 			std::deque<Plugin*>::iterator it = authplugins.begin();
 			String firstPlugin;
 			bool sslused = false;
