From 7e4630ced2be4b7ecdfb9d60cfe0e0d3de594411 Mon Sep 17 00:00:00 2001
From: Bastien Nocera <hadess@hadess.net>
Date: Mon, 27 Jan 2014 12:24:14 +0100
Subject: pam: Fix eventfd leak

When we create our own GMainContext, we need to be the ones
disposing of it as well, as GMainLoop won't take ownership of it.

From https://bugzilla.redhat.com/show_bug.cgi?id=1050827

diff --git a/pam/pam_fprintd.c b/pam/pam_fprintd.c
index 0f5e5a4..07302a1 100644
--- pam/pam_fprintd.c
+++ pam/pam_fprintd.c
@@ -170,6 +170,17 @@ static void close_and_unref (DBusGConnection *connection)
 	dbus_g_connection_unref (connection);
 }
 
+static void unref_loop (GMainLoop *loop)
+{
+	GMainContext *ctx;
+
+	/* The main context was created separately, so
+	 * we'll need to unref it ourselves */
+	ctx = g_main_loop_get_context (loop);
+	g_main_loop_unref (loop);
+	g_main_context_unref (ctx);
+}
+
 #define DBUS_TYPE_G_OBJECT_PATH_ARRAY (dbus_g_type_get_collection ("GPtrArray", DBUS_TYPE_G_OBJECT_PATH))
 
 static DBusGProxy *open_device(pam_handle_t *pamh, DBusGConnection *connection, DBusGProxy *manager, const char *username, gboolean *has_multiple_devices)
@@ -397,13 +408,13 @@ static int do_auth(pam_handle_t *pamh, const char *username)
 	dev = open_device(pamh, connection, manager, username, &has_multiple_devices);
 	g_object_unref (manager);
 	if (!dev) {
-		g_main_loop_unref (loop);
+		unref_loop (loop);
 		close_and_unref (connection);
 		return PAM_AUTHINFO_UNAVAIL;
 	}
 	ret = do_verify(loop, pamh, dev, has_multiple_devices);
 
-	g_main_loop_unref (loop);
+	unref_loop (loop);
 	release_device(pamh, dev);
 	g_object_unref (dev);
 	close_and_unref (connection);
-- 
cgit v0.10.2

