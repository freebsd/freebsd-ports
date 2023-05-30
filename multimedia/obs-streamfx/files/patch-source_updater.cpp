--- source/updater.cpp.orig	2023-05-20 18:52:40 UTC
+++ source/updater.cpp
@@ -77,7 +77,7 @@ void streamfx::from_json(const nlohmann::json& json, v
 	stage = stage_from_string(json.get<std::string>());
 }
 
-streamfx::version_info::version_info() : major(0), minor(0), patch(0), tweak(0), stage(version_stage::STABLE), url(""), name("") {}
+streamfx::version_info::version_info() : major_(0), minor_(0), patch(0), tweak(0), stage(version_stage::STABLE), url(""), name("") {}
 
 streamfx::version_info::version_info(const std::string text) : version_info()
 {
@@ -90,8 +90,8 @@ streamfx::version_info::version_info(const std::string
 	static const std::regex re_version("([0-9]+)\\.([0-9]+)\\.([0-9]+)(([\\._abc]{1,1})([0-9]+|)|)(-g([0-9a-fA-F]{8,8})|)");
 	std::smatch             matches;
 	if (std::regex_match(text, matches, re_version, std::regex_constants::match_any | std::regex_constants::match_continuous)) {
-		major = static_cast<uint16_t>(strtoul(matches[1].str().c_str(), nullptr, 10));
-		minor = static_cast<uint16_t>(strtoul(matches[2].str().c_str(), nullptr, 10));
+		major_ = static_cast<uint16_t>(strtoul(matches[1].str().c_str(), nullptr, 10));
+		minor_ = static_cast<uint16_t>(strtoul(matches[2].str().c_str(), nullptr, 10));
 		patch = static_cast<uint16_t>(strtoul(matches[3].str().c_str(), nullptr, 10));
 		if (matches.size() >= 5) {
 			stage = stage_from_string(matches[5].str());
@@ -105,8 +105,8 @@ streamfx::version_info::version_info(const std::string
 void streamfx::to_json(nlohmann::json& json, const version_info& info)
 {
 	auto version     = nlohmann::json::object();
-	version["major"] = info.major;
-	version["minor"] = info.minor;
+	version["major"] = info.major_;
+	version["minor"] = info.minor_;
 	version["patch"] = info.patch;
 	version["type"]  = info.stage;
 	version["tweak"] = info.tweak;
@@ -119,8 +119,8 @@ void streamfx::from_json(const nlohmann::json& json, v
 {
 	if (json.find("html_url") == json.end()) {
 		auto version = json.at("version");
-		info.major   = version.at("major").get<uint16_t>();
-		info.minor   = version.at("minor").get<uint16_t>();
+		info.major_   = version.at("major").get<uint16_t>();
+		info.minor_   = version.at("minor").get<uint16_t>();
 		info.patch   = version.at("patch").get<uint16_t>();
 		info.stage   = version.at("type");
 		info.tweak   = version.at("tweak").get<uint16_t>();
@@ -152,19 +152,19 @@ bool streamfx::version_info::is_older_than(const versi
 
 	// Compare Major version:
 	// - Theirs is greater: Remote is newer.
-	if (major < other.major)
+	if (major_ < other.major_)
 		return true;
 	// - Ours is greater: Remote is older.
-	if (major > other.major)
+	if (major_ > other.major_)
 		return false;
 	// - Continue the check.
 
 	// Compare Minor version:
 	// - Theirs is greater: Remote is newer.
-	if (minor < other.minor)
+	if (minor_ < other.minor_)
 		return true;
 	// - Ours is greater: Remote is older.
-	if (minor > other.minor)
+	if (minor_ > other.minor_)
 		return false;
 	// - Continue the check.
 
@@ -209,10 +209,10 @@ streamfx::version_info::operator std::string()
 	std::vector<char> buffer(25, 0);
 	if (stage != version_stage::STABLE) {
 		auto types = stage_to_string(stage);
-		int  len   = snprintf(buffer.data(), buffer.size(), "%" PRIu16 ".%" PRIu16 ".%" PRIu16 "%.1s%" PRIu16, major, minor, patch, types.data(), tweak);
+		int  len   = snprintf(buffer.data(), buffer.size(), "%" PRIu16 ".%" PRIu16 ".%" PRIu16 "%.1s%" PRIu16, major_, minor_, patch, types.data(), tweak);
 		return std::string(buffer.data(), buffer.data() + len);
 	} else {
-		int len = snprintf(buffer.data(), buffer.size(), "%" PRIu16 ".%" PRIu16 ".%" PRIu16, major, minor, patch);
+		int len = snprintf(buffer.data(), buffer.size(), "%" PRIu16 ".%" PRIu16 ".%" PRIu16, major_, minor_, patch);
 		return std::string(buffer.data(), buffer.data() + len);
 	}
 }
