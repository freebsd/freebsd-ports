--- a/frontend.c.orig	2012-05-11 07:37:27 UTC
+++ b/frontend.c
@@ -91,7 +91,7 @@ void cXinelibThread::KeypressHandler(con
     if (!remote->Put(key, repeat, release)) {
       if (!strcmp(keymap, "KBD")) {
         uint64_t value = 0;
-        sscanf(key, "%"PRIX64, &value);
+        sscanf(key, "%" 	PRIX64, &value);
         if (value) {
           remote->cRemote::Put(KBDKEY(value));
           return;
