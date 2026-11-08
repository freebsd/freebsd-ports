-- Dash enables its async page router as soon as asgiref imports, and
-- www/py-flask pulls that in. flask-socketio runs the server
-- synchronously, so the router's coroutine is never awaited and every
-- page comes up empty.

--- src/app.py.orig	2026-11-07 08:38:02 UTC
+++ src/app.py
@@ -29,6 +29,7 @@ app = dash.Dash(
 		{"rel": "icon", "type": "image/x-icon", "href": "/assets/favicon.ico"}
 	],
 	suppress_callback_exceptions=True,
+	use_async=False,
 	use_pages=True,
 	pages_folder="pages",
 )
