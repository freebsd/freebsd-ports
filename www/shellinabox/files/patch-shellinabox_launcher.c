--- shellinabox/launcher.c.orig	2016-11-09 19:40:33 UTC
+++ shellinabox/launcher.c
@@ -993,8 +993,8 @@ static pam_handle_t *internalLogin(struct Service *ser
   if (service->authUser == 2 /* SSH */) {
     // If connecting to a remote host, include that hostname
     hostname                   = strrchr(service->cmdline, '@');
-    if (!hostname || !strcmp(++hostname, "localhost")) {
-      hostname                 = NULL;
+    if (hostname) {
+      hostname++;
     }
   }
   struct utsname uts;
