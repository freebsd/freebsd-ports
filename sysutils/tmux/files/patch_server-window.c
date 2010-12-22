@@ -109,10 +109,8 @@
 
 	if (!(w->flags & WINDOW_BELL) || wl->flags & WINLINK_BELL)
 		return (0);
-	if (s->curw == wl)
-		return (0);
-
-	wl->flags |= WINLINK_BELL;
+	if (s->curw != wl)
+		wl->flags |= WINLINK_BELL;
 
 	action = options_get_number(&s->options, "bell-action");
 	switch (action) {
