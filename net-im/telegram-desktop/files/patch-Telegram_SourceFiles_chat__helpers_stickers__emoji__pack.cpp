--- Telegram/SourceFiles/chat_helpers/stickers_emoji_pack.cpp.orig	2021-10-08 09:51:22 UTC
+++ Telegram/SourceFiles/chat_helpers/stickers_emoji_pack.cpp
@@ -99,7 +99,7 @@ constexpr auto kRefreshTimeout = 7200 * crl::time(1000
 		},
 		5,
 	};
-	static const auto list = std::array{
+	static const auto list = std::array<const Lottie::ColorReplacements*, 5>{
 		&color1,
 		&color2,
 		&color3,
