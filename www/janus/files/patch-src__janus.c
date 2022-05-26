--- src/janus.c.orig	2022-05-23 09:14:54 UTC
+++ src/janus.c
@@ -4449,6 +4449,7 @@ gint main(int argc, char *argv[]) {
 				if (exit_on_dl_error)
 					exit(1);
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
@@ -5474,6 +5475,7 @@ gint main(int argc, char *argv[]) {
 				exit(1);
 			}
 		} else {
+			dlerror();
 			create_p *create = (create_p*) dlsym(plugin, "create");
 			const char *dlsym_error = dlerror();
 			if(dlsym_error) {
