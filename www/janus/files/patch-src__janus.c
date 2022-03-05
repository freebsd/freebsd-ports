--- src/janus.c.orig	2022-03-03 10:44:38 UTC
+++ src/janus.c
@@ -4435,6 +4435,7 @@ gint main(int argc, char *argv[])
 				if (exit_on_dl_error)
 					exit(1);
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
@@ -5459,6 +5460,7 @@ gint main(int argc, char *argv[])
 			if (exit_on_dl_error)
 				exit(1);
 		} else {
+			dlerror();
 			create_p *create = (create_p*) dlsym(plugin, "create");
 			const char *dlsym_error = dlerror();
 			if (dlsym_error) {
