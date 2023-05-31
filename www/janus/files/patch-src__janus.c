--- src/janus.c.orig	2023-05-20 12:59:00 UTC
+++ src/janus.c
@@ -4618,6 +4618,7 @@ gint main(int argc, char *argv[]) {
 				if (exit_on_dl_error)
 					exit(1);
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
@@ -5649,6 +5650,7 @@ gint main(int argc, char *argv[]) {
 				exit(1);
 			}
 		} else {
+			dlerror();
 			create_p *create = (create_p*) dlsym(plugin, "create");
 			const char *dlsym_error = dlerror();
 			if(dlsym_error) {
