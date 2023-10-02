--- Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp.orig	2023-09-29 15:29:53 UTC
+++ Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp
@@ -53,6 +53,10 @@ bool ServiceRegistered = false;
 ServerInformation CurrentServerInformation;
 std::vector<Glib::ustring> CurrentCapabilities;
 
+[[nodiscard]] bool HasCapability(const char *value) {
+	return ranges::contains(CurrentCapabilities, value, &Glib::ustring::raw);
+}
+
 void Noexcept(Fn<void()> callback, Fn<void()> failed = nullptr) noexcept {
 	try {
 		callback();
@@ -446,7 +450,6 @@ bool NotificationData::init(
 	}
 
 	const auto weak = base::make_weak(this);
-	const auto &capabilities = CurrentCapabilities;
 
 	const auto signalEmitted = crl::guard(weak, [=](
 			const Glib::RefPtr<Gio::DBus::Connection> &connection,
@@ -496,7 +499,7 @@ bool NotificationData::init(
 
 	_imageKey = GetImageKey(CurrentServerInformation.specVersion);
 
-	if (ranges::contains(capabilities, "body-markup")) {
+	if (HasCapability("body-markup")) {
 		_title = title.toStdString();
 
 		_body = subtitle.isEmpty()
@@ -512,7 +515,7 @@ bool NotificationData::init(
 		_body = msg.toStdString();
 	}
 
-	if (ranges::contains(capabilities, "actions")) {
+	if (HasCapability("actions")) {
 		_actions.push_back("default");
 		_actions.push_back(tr::lng_open_link(tr::now).toStdString());
 
@@ -523,7 +526,7 @@ bool NotificationData::init(
 				tr::lng_context_mark_read(tr::now).toStdString());
 		}
 
-		if (ranges::contains(capabilities, "inline-reply")
+		if (HasCapability("inline-reply")
 			&& !options.hideReplyButton) {
 			_actions.push_back("inline-reply");
 			_actions.push_back(
@@ -553,13 +556,13 @@ bool NotificationData::init(
 			kObjectPath);
 	}
 
-	if (ranges::contains(capabilities, "action-icons")) {
+	if (HasCapability("action-icons")) {
 		_hints["action-icons"] = Glib::create_variant(true);
 	}
 
 	// suppress system sound if telegram sound activated,
 	// otherwise use system sound
-	if (ranges::contains(capabilities, "sound")) {
+	if (HasCapability("sound")) {
 		if (Core::App().settings().soundNotify()) {
 			_hints["suppress-sound"] = Glib::create_variant(true);
 		} else {
@@ -569,7 +572,7 @@ bool NotificationData::init(
 		}
 	}
 
-	if (ranges::contains(capabilities, "x-canonical-append")) {
+	if (HasCapability("x-canonical-append")) {
 		_hints["x-canonical-append"] = Glib::create_variant(
 			Glib::ustring("true"));
 	}
@@ -805,7 +808,7 @@ bool ByDefault() {
 
 	// A list of capabilities that offer feature parity
 	// with custom notifications
-	return ranges::all_of(std::initializer_list{
+	return ranges::all_of(std::array{
 		// To show message content
 		"body",
 		// To have buttons on notifications
@@ -816,7 +819,7 @@ bool ByDefault() {
 		// (no, using sound capability is not a way)
 		"inhibitions",
 	}, [](const auto *capability) {
-		return ranges::contains(CurrentCapabilities, capability);
+		return HasCapability(capability);
 	});
 }
 
@@ -909,7 +912,6 @@ class Manager::Private : public base::has_weak_ptr { (
 Manager::Private::Private(not_null<Manager*> manager)
 : _manager(manager) {
 	const auto &serverInformation = CurrentServerInformation;
-	const auto &capabilities = CurrentCapabilities;
 
 	if (!serverInformation.name.empty()) {
 		LOG(("Notification daemon product name: %1")
@@ -931,17 +933,17 @@ Manager::Private::Private(not_null<Manager*> manager)
 			.arg(serverInformation.specVersion.toString()));
 	}
 
-	if (!capabilities.empty()) {
+	if (!CurrentCapabilities.empty()) {
 		LOG(("Notification daemon capabilities: %1").arg(
 			ranges::fold_left(
-				capabilities,
+				CurrentCapabilities,
 				"",
 				[](const Glib::ustring &a, const Glib::ustring &b) {
 					return a + (a.empty() ? "" : ", ") + b;
 				}).c_str()));
 	}
 
-	if (ranges::contains(capabilities, "inhibitions")) {
+	if (HasCapability("inhibitions")) {
 		Noexcept([&] {
 			_dbusConnection = Gio::DBus::Connection::get_sync(
 				Gio::DBus::BusType::SESSION);
