--- src/GUI/file_browser.c.orig	2021-12-15 17:05:37 UTC
+++ src/GUI/file_browser.c
@@ -13,6 +13,7 @@
 #endif
 #if UNIX
 #include <unistd.h>
+#include <pwd.h>
 #endif
 #include <GL/glew.h>
 #include <string.h>
@@ -325,8 +326,13 @@ void file_browser_init(struct file_browser *browser, s
 		if (!home)
 			home = getenv("USERPROFILE");
 #else
-		if (!home)
-			home = getpwuid(getuid());
+		if (!home) {
+			struct passwd *pwd;
+
+			pwd = getpwuid(getuid());
+			if (pwd != NULL)
+				home = pwd->pw_dir;
+		}
 #endif
 		{
 			size_t l;
