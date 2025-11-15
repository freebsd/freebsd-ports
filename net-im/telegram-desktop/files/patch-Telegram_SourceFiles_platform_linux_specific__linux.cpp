--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	2025-11-15 22:57:35 UTC
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp
@@ -68,7 +68,7 @@ void PortalAutostart(bool enabled, Fn<void(bool)> done
 		Gio::DBusProxyFlags::NONE_,
 		base::Platform::XDP::kService,
 		base::Platform::XDP::kObjectPath,
-		[=](GObject::Object, Gio::AsyncResult res) {
+		[=](auto, Gio::AsyncResult res) {
 			auto proxy = XdpBackground::BackgroundProxy::new_for_bus_finish(
 				res);
 
@@ -121,7 +121,7 @@ void PortalAutostart(bool enabled, Fn<void(bool)> done
 					+ '/'
 					+ handleToken,
 				nullptr,
-				[=](GObject::Object, Gio::AsyncResult res) mutable {
+				[=](auto, Gio::AsyncResult res) mutable {
 					auto requestProxy = XdpRequest::RequestProxy::new_finish(
 						res);
 
@@ -196,7 +196,7 @@ void PortalAutostart(bool enabled, Fn<void(bool)> done
 								GLib::Variant::new_variant(
 									GLib::Variant::new_boolean(false))),
 						}),
-						[=](GObject::Object, Gio::AsyncResult res) mutable {
+						[=](auto, Gio::AsyncResult res) mutable {
 							auto &sandbox = Core::Sandbox::Instance();
 							sandbox.customEnterFromEventLoop([&] {
 								const auto result =
@@ -451,7 +451,7 @@ bool GenerateServiceFile(bool silent = false) {
 		Gio::DBusProxyFlags::NONE_,
 		base::Platform::DBus::kService,
 		base::Platform::DBus::kObjectPath,
-		[=](GObject::Object, Gio::AsyncResult res) {
+		[=](auto, Gio::AsyncResult res) {
 			auto interface = XdgDBus::DBus(
 				XdgDBus::DBusProxy::new_for_bus_finish(res, nullptr));
 
@@ -804,7 +804,7 @@ void LaunchMaps(const Data::LocationPoint &point, Fn<v
 		Gio::DBusProxyFlags::NONE_,
 		base::Platform::XDP::kService,
 		base::Platform::XDP::kObjectPath,
-		[=](GObject::Object, Gio::AsyncResult res) {
+		[=](auto, Gio::AsyncResult res) {
 			auto interface = XdpOpenURI::OpenURI(
 				XdpOpenURI::OpenURIProxy::new_for_bus_finish(res, nullptr));
 
@@ -818,7 +818,7 @@ void LaunchMaps(const Data::LocationPoint &point, Fn<v
 				GLib::Variant::new_array(
 					GLib::VariantType::new_("{sv}"),
 					{}),
-				[=](GObject::Object, Gio::AsyncResult res) mutable {
+				[=](auto, Gio::AsyncResult res) mutable {
 					const auto result
 						= interface.call_scheme_supported_finish(res);
 
