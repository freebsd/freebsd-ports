--- Telegram/lib_base/base/platform/linux/base_linux_xcb_utilities.cpp.orig	2025-01-04 14:57:59 UTC
+++ Telegram/lib_base/base/platform/linux/base_linux_xcb_utilities.cpp
@@ -139,7 +139,7 @@ rpl::lifetime InstallEventHandler(
 		}
 	}
 
-	const auto ptr = it->second.second.emplace_back(new Fn(handler)).get();
+	const auto ptr = it->second.second.emplace_back(new std::function(handler)).get();
 	return rpl::lifetime([=] {
 		const auto it = EventHandlers.find(connection);
 		it->second.second.erase(
