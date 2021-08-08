--- janus.c.orig	2021-08-02 14:04:13 UTC
+++ janus.c
@@ -4282,6 +4282,7 @@ gint main(int argc, char *argv[])
 			if (!event) {
 				JANUS_LOG(LOG_ERR, "\tCouldn't load logger plugin '%s': %s\n", eventent->d_name, dlerror());
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
