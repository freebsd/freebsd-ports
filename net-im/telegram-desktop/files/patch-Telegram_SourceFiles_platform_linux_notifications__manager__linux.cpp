--- Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp.orig	2022-12-07 09:41:04 UTC
+++ Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp
@@ -75,12 +75,17 @@ std::unique_ptr<base::Platform::DBus::ServiceWatcher> 
 	try {
 		const auto connection = Gio::DBus::Connection::get_sync(
 			Gio::DBus::BusType::SESSION);
+		const auto GlibNames =
+			base::Platform::DBus::ListActivatableNames(connection);
+		const std::vector<std::string> StringNames(
+			GlibNames.begin(), GlibNames.end()
+		);
 
 		const auto activatable = [&] {
 			try {
 				return ranges::contains(
-					base::Platform::DBus::ListActivatableNames(connection),
-					Glib::ustring(std::string(kService)));
+					StringNames,
+					std::string(kService));
 			} catch (...) {
 				// avoid service restart loop in sandboxed environments
 				return true;
@@ -129,7 +134,7 @@ void StartServiceAsync(Fn<void()> callback) {
 						};
 
 						const auto errorName =
-							Gio::DBus::ErrorUtils::get_remote_error(e);
+							Gio::DBus::ErrorUtils::get_remote_error(e).raw();
 
 						if (!ranges::contains(NotSupportedErrors, errorName)) {
 							throw e;
@@ -151,6 +156,11 @@ bool GetServiceRegistered() {
 	try {
 		const auto connection = Gio::DBus::Connection::get_sync(
 			Gio::DBus::BusType::SESSION);
+		const auto GlibNames =
+			base::Platform::DBus::ListActivatableNames(connection);
+		const std::vector<std::string> StringNames(
+			GlibNames.begin(), GlibNames.end()
+		);
 
 		const auto hasOwner = [&] {
 			try {
@@ -165,8 +175,8 @@ bool GetServiceRegistered() {
 		static const auto activatable = [&] {
 			try {
 				return ranges::contains(
-					DBus::ListActivatableNames(connection),
-					Glib::ustring(std::string(kService)));
+					StringNames,
+					std::string(kService));
 			} catch (...) {
 				return false;
 			}
