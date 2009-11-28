From c61c318aabdc980477dccd78549fe9819c3b1fa0 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Fr=C3=A9d=C3=A9ric=20P=C3=A9ters?= <fpeters@0d.be>
Date: Fri, 9 Oct 2009 20:07:20 +0200
Subject: [PATCH] Pass mailto: URI to gtk_show_uri()

(Part of) Bug #584537
---
 src/ephy-window.c |    8 ++++++++
 1 files changed, 8 insertions(+), 0 deletions(-)

diff --git a/src/ephy-window.c b/src/ephy-window.c
index 635a779..630ecec 100644
--- src/ephy-window.c
+++ src/ephy-window.c
@@ -2548,10 +2548,18 @@ policy_decision_required_cb (WebKitWebView *web_view,
 	WebKitWebNavigationReason reason;
 	gint button;
 	gint state;
+	const char *uri;
 
 	reason = webkit_web_navigation_action_get_reason (action);
 	button = webkit_web_navigation_action_get_button (action);
 	state = webkit_web_navigation_action_get_modifier_state (action);
+	uri = webkit_network_request_get_uri (request);
+
+	if (strncmp (uri, "mailto:", 7) == 0) {
+		webkit_web_policy_decision_ignore (decision);
+		gtk_show_uri (NULL, uri, GDK_CURRENT_TIME, NULL);
+		return TRUE;
+	}
 
 	/* Open in new tab for middle click or ctrl+click */
 	if (reason == WEBKIT_WEB_NAVIGATION_REASON_LINK_CLICKED &&
-- 
1.6.4.3
