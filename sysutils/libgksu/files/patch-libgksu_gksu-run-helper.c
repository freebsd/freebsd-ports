--- libgksu/gksu-run-helper.c.orig	Thu Sep 30 20:40:25 2004
+++ libgksu/gksu-run-helper.c	Thu Sep 30 19:09:05 2004
@@ -127,9 +127,9 @@
     chmod (tmpfilename, S_IRUSR|S_IWUSR);
     
     command =
-      g_strdup_printf ("/usr/bin/env -u XAUTHORITY=%s /usr/X11R6/bin/xauth add %s . \"`cat %s.tmp`\" > /dev/null 2>&1; /usr/bin/env -u XAUTHORITY=%s %s",
-		       xauth_file, xauth_display,
-		       xauth_file, xauth_file,
+      g_strdup_printf ("/bin/sh -c unset XAUTHORITY; /usr/X11R6/bin/xauth add %s . \"`cat %s.tmp`\" > /dev/null 2>&1; /bin/sh -c unset XAUTHORITY; %s",
+		       xauth_display,
+		       xauth_file,
 		       argv[1]);
     
     return_code = system (command);
