From 9c164b2afb666d0bcd26ba3eeb6da07a9fff551c Mon Sep 17 00:00:00 2001
From: Yawning Angel <yawning@torproject.org>
Date: Sat, 14 Jun 2014 23:09:08 +0000
Subject: Suppress more useless warnings.

Apparently I forgot to check the IAT code when I switched to building
wiht -Wextra, since no one should use it.
---
 src/schwanenlied/pt/scramblesuit/client.cc | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)

diff --git a/src/schwanenlied/pt/scramblesuit/client.cc b/src/schwanenlied/pt/scramblesuit/client.cc
index e967b7b..c6e1a20 100644
--- src/schwanenlied/pt/scramblesuit/client.cc
+++ src/schwanenlied/pt/scramblesuit/client.cc
@@ -468,8 +468,10 @@ bool Client::schedule_iat_transmit() {
   // Lazy timer initialization
   if (iat_timer_ev_ == nullptr) {
     event_callback_fn cb = [](evutil_socket_t sock,
-                              short witch,
+                              short which,
                               void* arg) {
+      (void)sock;
+      (void)which;
       reinterpret_cast<Client*>(arg)->on_iat_transmit();
     };
     iat_timer_ev_ = evtimer_new(base_, cb, this);
-- 
2.3.0

