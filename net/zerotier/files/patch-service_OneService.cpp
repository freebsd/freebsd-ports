--- service/OneService.cpp.orig	2023-09-14 19:09:26 UTC
+++ service/OneService.cpp
@@ -795,6 +795,7 @@ class OneServiceImpl : public OneService (public)
     bool _allowTcpFallbackRelay;
 	bool _forceTcpRelay;
 	bool _allowSecondaryPort;
+	bool _enableWebServer;
 
 	unsigned int _primaryPort;
 	unsigned int _secondaryPort;
@@ -1557,6 +1558,7 @@ class OneServiceImpl : public OneService (public)
 
         std::vector<std::string> noAuthEndpoints { "/sso", "/health" };
 
+
 		auto setContent = [=] (const httplib::Request &req, httplib::Response &res, std::string content) {
 			if (req.has_param("jsonp")) {
 				if (content.length() > 0) {
@@ -1573,8 +1575,98 @@ class OneServiceImpl : public OneService (public)
 			}
 		};
 
+		//
+		// static file server for app ui'
+		//
+		if (_enableWebServer) {
+			static std::string appUiPath = "/app";
+			static char appUiDir[16384];
+			sprintf(appUiDir,"%s%s",_homePath.c_str(),appUiPath.c_str());
 
-        auto authCheck = [=] (const httplib::Request &req, httplib::Response &res) {
+			auto ret = _controlPlane.set_mount_point(appUiPath, appUiDir);
+			_controlPlaneV6.set_mount_point(appUiPath, appUiDir);
+			if (!ret) {
+				fprintf(stderr, "Mounting app directory failed. Creating it. Path: %s - Dir: %s\n", appUiPath.c_str(), appUiDir);
+				if (!OSUtils::mkdir(appUiDir)) {
+					fprintf(stderr, "Could not create app directory either. Path: %s - Dir: %s\n", appUiPath.c_str(), appUiDir);
+				} else {
+					ret = _controlPlane.set_mount_point(appUiPath, appUiDir);
+					_controlPlaneV6.set_mount_point(appUiPath, appUiDir);
+					if (!ret) {
+						fprintf(stderr, "Really could not create and mount directory. Path: %s - Dir: %s\nWeb apps won't work.\n", appUiPath.c_str(), appUiDir);
+					}
+				}
+			}
+
+			if (ret) {
+				// fallback to /index.html for paths that don't exist for SPAs
+				auto indexFallbackGet = [](const httplib::Request &req, httplib::Response &res) {
+					// fprintf(stderr, "fallback \n");
+
+					auto match = req.matches[1];
+					if (match.matched) {
+
+						// fallback
+						char indexHtmlPath[16384];
+						sprintf(indexHtmlPath,"%s/%s/%s", appUiDir, match.str().c_str(), "index.html");
+						// fprintf(stderr, "fallback path %s\n", indexHtmlPath);
+
+						std::string indexHtml;
+
+						if (!OSUtils::readFile(indexHtmlPath, indexHtml)) {
+							res.status = 500;
+							return;
+						}
+
+						res.set_content(indexHtml.c_str(), "text/html");
+					} else {
+						res.status = 500;
+						return;
+					}
+				};
+
+				auto slashRedirect = [](const httplib::Request &req, httplib::Response &res) {
+					// fprintf(stderr, "redirect \n");
+
+					// add .html
+					std::string htmlFile;
+					char htmlPath[16384];
+					sprintf(htmlPath,"%s%s%s", appUiDir, (req.path).substr(appUiPath.length()).c_str(), ".html");
+					// fprintf(stderr, "path: %s\n", htmlPath);
+					if (OSUtils::readFile(htmlPath, htmlFile)) {
+						res.set_content(htmlFile.c_str(), "text/html");
+						return;
+					} else {
+						res.status = 301;
+						res.set_header("location", req.path + "/");
+					}
+				};
+
+				// auto missingAssetGet = [&, setContent](const httplib::Request &req, httplib::Response &res) {
+				// 	fprintf(stderr, "missing \n");
+				// 	res.status = 404;
+				// 	std::string html = "oops";
+				// 	res.set_content(html, "text/plain");
+				// 	res.set_header("Content-Type", "text/plain");
+				// 	return;
+				// };
+
+				// auto fix no trailing slash by adding .html or redirecting to path/
+				_controlPlane.Get(appUiPath + R"((/[\w|-]+)+$)", slashRedirect);
+				_controlPlaneV6.Get(appUiPath + R"((/[\w|-]+)+$)", slashRedirect);
+
+				// // 404 missing assets for *.ext paths
+				//   s.Get(appUiPath + R"(/\.\w+$)", missingAssetGet);
+				// sv6.Get(appUiPath + R"(/\.\w+$)", missingAssetGet);
+
+				// fallback to index.html for unknown paths/files
+				_controlPlane.Get(appUiPath + R"((/[\w|-]+)(/[\w|-]+)*/$)", indexFallbackGet);
+				_controlPlaneV6.Get(appUiPath + R"((/[\w|-]+)(/[\w|-]+)*/$)", indexFallbackGet);
+
+			}
+		}
+
+		auto authCheck = [=] (const httplib::Request &req, httplib::Response &res) {
 			if (req.path == "/metrics") {
 
 				if (req.has_header("x-zt1-auth")) {
@@ -1624,6 +1716,11 @@ class OneServiceImpl : public OneService (public)
 						isAuth = true;
 					}
 
+					// Web Apps base path
+					if (req.path.rfind("/app", 0) == 0) { //starts with /app
+						isAuth = true;
+					}
+
 					if (!isAuth) {
 						// check auth token
 						if (req.has_header("x-zt1-auth")) {
@@ -2429,6 +2526,7 @@ class OneServiceImpl : public OneService (public)
 		// bondingPolicy cannot be used with allowTcpFallbackRelay
 		_allowTcpFallbackRelay = OSUtils::jsonBool(settings["allowTcpFallbackRelay"],true);
 		_forceTcpRelay = OSUtils::jsonBool(settings["forceTcpRelay"],false);
+		_enableWebServer = (OSUtils::jsonBool(settings["enableWebServer"],false));
 
 #ifdef ZT_TCP_FALLBACK_RELAY
 		_fallbackRelayAddress = InetAddress(OSUtils::jsonString(settings["tcpFallbackRelay"], ZT_TCP_FALLBACK_RELAY).c_str());
