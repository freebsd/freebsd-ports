--- Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp.orig	2023-10-02 20:31:34 UTC
+++ Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp
@@ -814,7 +814,7 @@ bool ByDefault() {
 
 	// A list of capabilities that offer feature parity
 	// with custom notifications
-	return ranges::all_of(std::initializer_list{
+	return ranges::all_of(std::array{
 		// To show message content
 		"body",
 		// To have buttons on notifications
