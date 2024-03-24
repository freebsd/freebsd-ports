--- controller/EmbeddedNetworkController.cpp.orig	2023-09-14 19:09:26 UTC
+++ controller/EmbeddedNetworkController.cpp
@@ -874,6 +874,7 @@ void EmbeddedNetworkController::configureHTTPControlPl
 	std::string memberListPath = "/controller/network/([0-9a-fA-F]{16})/member";
 	std::string memberPath = "/controller/network/([0-9a-fA-F]{16})/member/([0-9a-fA-F]{10})";
 
+
 	auto controllerGet = [&, setContent](const httplib::Request &req, httplib::Response &res) {
 		char tmp[4096];
 		const bool dbOk = _db.isReady();
@@ -885,11 +886,11 @@ void EmbeddedNetworkController::configureHTTPControlPl
 			(unsigned long long)OSUtils::now(),
 			dbOk ? "true" : "false");
 
-			if (!dbOk) {
-				res.status = 503;
-			}
+		if (!dbOk) {
+			res.status = 503;
+		}
 
-			setContent(req, res, tmp);
+		setContent(req, res, tmp);
 	};
 	s.Get(controllerPath, controllerGet);
 	sv6.Get(controllerPath, controllerGet);
