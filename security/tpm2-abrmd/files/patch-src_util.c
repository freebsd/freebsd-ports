--- src/util.c.orig	2025-02-22 21:59:15 UTC
+++ src/util.c
@@ -68,7 +68,7 @@ ssize_t
 /** Write as many of the size bytes from buf to fd as possible.
  */
 ssize_t
-write_all (GOutputStream *ostream,
+g_write_all (GOutputStream *ostream,
            const uint8_t *buf,
            const size_t   size)
 {
@@ -77,14 +77,15 @@ write_all (GOutputStream *ostream,
     GError *error = NULL;
 
     do {
-        g_debug ("%s: writing %zu bytes to ostream", __func__,
-                 size - written_total);
+        g_debug ("%s: writing %zu bytes to ostream from %zu", __func__,
+                 size - written_total, buf);
         written = g_output_stream_write (ostream,
                                          (const gchar*)&buf [written_total],
                                          size - written_total,
                                          NULL,
                                          &error);
-        switch (written) {
+        g_debug ("Passed");
+	switch (written) {
         case -1:
             g_assert (error != NULL);
             g_warning ("%s: failed to write to ostream: %s", __func__, error->message);
