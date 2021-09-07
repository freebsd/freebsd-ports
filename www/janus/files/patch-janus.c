--- janus.c.orig	2021-09-06 10:07:06 UTC
+++ janus.c
@@ -4338,6 +4338,7 @@ gint main(int argc, char *argv[])
 			if (!event) {
 				JANUS_LOG(LOG_ERR, "\tCouldn't load logger plugin '%s': %s\n", eventent->d_name, dlerror());
 			} else {
+				dlerror();
 				create_l *create = (create_l*) dlsym(event, "create");
 				const char *dlsym_error = dlerror();
 				if (dlsym_error) {
