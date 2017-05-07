--- clients/screenshot.c.orig	2016-05-19 21:36:04 UTC
+++ clients/screenshot.c
@@ -257,7 +257,7 @@ int main(int argc, char *argv[])
 	if (getenv("WAYLAND_SOCKET") == NULL) {
 		fprintf(stderr, "%s must be launched by weston.\n"
 			"Use the MOD+S shortcut to take a screenshot.\n",
-			program_invocation_short_name);
+			getprogname());
 		return -1;
 	}
 
