--- Telegram/lib_base/base/platform/linux/base_last_input_linux.cpp.orig	2022-12-07 06:59:17 UTC
+++ Telegram/lib_base/base/platform/linux/base_last_input_linux.cpp
@@ -103,7 +103,7 @@ std::optional<crl::time> FreedesktopDBusLastUserInputT
 			"org.freedesktop.DBus.Error.AccessDenied",
 		};
 
-		const auto errorName = Gio::DBus::ErrorUtils::get_remote_error(e);
+		const auto errorName = Gio::DBus::ErrorUtils::get_remote_error(e).raw();
 		if (ranges::contains(NotSupportedErrors, errorName)) {
 			NotSupported = true;
 			return std::nullopt;
@@ -163,7 +163,7 @@ std::optional<crl::time> MutterDBusLastUserInputTime()
 			"org.freedesktop.DBus.Error.AccessDenied",
 		};
 
-		const auto errorName = Gio::DBus::ErrorUtils::get_remote_error(e);
+		const auto errorName = Gio::DBus::ErrorUtils::get_remote_error(e).raw();
 		if (ranges::contains(NotSupportedErrors, errorName)) {
 			NotSupported = true;
 			return std::nullopt;

