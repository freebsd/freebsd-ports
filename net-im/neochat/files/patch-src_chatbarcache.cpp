From 9cd4a7416e0485917334c9448ce09c1800dca2ed Mon Sep 17 00:00:00 2001
From: Tobias Fella <fella@posteo.de>
Date: Tue, 10 Dec 2024 21:05:01 +0100
Subject: [PATCH] Fix crash when sending messages

ECM recently started adding -fhardened, which makes us crash here since we're doing things that aren't valid, but happened to work out fine previously.
--- src/chatbarcache.cpp.orig	2024-12-04 20:04:56 UTC
+++ src/chatbarcache.cpp
@@ -319,7 +319,8 @@ void ChatBarCache::postMessage()
         return;
     }
 
-    room->postMessage(text(), sendText, *std::get<std::optional<Quotient::RoomMessageEvent::MsgType>>(result), replyId(), editId(), threadId());
+    const auto type = std::get<std::optional<Quotient::RoomMessageEvent::MsgType>>(result);
+    room->postMessage(text(), sendText, type ? *type : Quotient::RoomMessageEvent::MsgType::Text, replyId(), editId(), threadId());
     clearCache();
 }
 
