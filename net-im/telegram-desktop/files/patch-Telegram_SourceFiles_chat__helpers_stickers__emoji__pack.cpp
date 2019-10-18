--- Telegram/SourceFiles/chat_helpers/stickers_emoji_pack.cpp.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/chat_helpers/stickers_emoji_pack.cpp
@@ -107,7 +107,7 @@ constexpr auto kClearSourceTimeout = 10 * crl::time(10
 		},
 		5,
 	};
-	static const auto list = std::array{
+	static const auto list = std::array<const Lottie::ColorReplacements*, 5>{
 		&color1,
 		&color2,
 		&color3,
