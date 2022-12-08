--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	2022-12-07 09:41:04 UTC
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp
@@ -244,12 +244,16 @@ void LaunchGApplication() {
 	const auto activatableNames = [&] {
 		try {
 			if (connection) {
-				return ListActivatableNames(connection);
+				const auto GlibNames =
+				    ListActivatableNames(connection);
+				return std::vector<std::string>(
+				    GlibNames.begin(), GlibNames.end()
+				);
 			}
 		} catch (...) {
 		}
 
-		return std::vector<Glib::ustring>();
+		return std::vector<std::string>();
 	}();
 
 	const auto freedesktopNotifications = [&] {
@@ -356,7 +360,7 @@ void LaunchGApplication() {
 
 			using Window::Notifications::Manager;
 			using NotificationId = Manager::NotificationId;
-			using NotificationIdTuple = std::result_of<
+			using NotificationIdTuple = ranges::result_of<
 				decltype(&NotificationId::toTuple)(NotificationId*)
 			>::type;
 
@@ -731,7 +735,7 @@ void start() {
 					md5Hash.data());
 			}
 
-			return u"org.telegram.desktop._%1.desktop"_q.arg(md5Hash);
+			return u"org.telegram.desktop._%1.desktop"_q.arg(md5Hash.constData());
 		}
 
 		return u"org.telegram.desktop.desktop"_q;
