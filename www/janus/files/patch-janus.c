--- janus.c.orig	2022-02-11 08:56:29 UTC
+++ janus.c
@@ -4423,6 +4423,7 @@ gint main(int argc, char *argv[])
 				if (exit_on_dl_error)
 					exit(1);
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
@@ -5447,6 +5448,7 @@ gint main(int argc, char *argv[])
 			if (exit_on_dl_error)
 				exit(1);
 		} else {
+			dlerror();
 			create_p *create = (create_p*) dlsym(plugin, "create");
 			const char *dlsym_error = dlerror();
 			if (dlsym_error) {
