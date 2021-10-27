--- janus.c.orig	2021-10-18 15:46:53 UTC
+++ janus.c
@@ -4359,6 +4359,7 @@ gint main(int argc, char *argv[])
 			if (!event) {
 				JANUS_LOG(LOG_ERR, "\tCouldn't load logger plugin '%s': %s\n", eventent->d_name, dlerror());
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
