--- Telegram/SourceFiles/chat_helpers/stickers_emoji_pack.cpp.orig	2019-09-27 17:04:25 UTC
+++ Telegram/SourceFiles/chat_helpers/stickers_emoji_pack.cpp
@@ -105,7 +105,7 @@ constexpr auto kClearSourceTimeout = 10 * crl::time(10
 		},
 		5,
 	};
-	static const auto list = std::array{
+	static const auto list = std::array<const Lottie::ColorReplacements*, 5>{
 		&color1,
 		&color2,
 		&color3,
