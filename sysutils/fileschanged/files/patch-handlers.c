--- src/handlers.c.orig	Mon Feb 23 01:42:46 2004
+++ src/handlers.c	Wed Jun 16 20:13:06 2004
@@ -7,6 +7,11 @@
 #include "node.h"
 #include "opts.h"
 #include "wl.h"
+#if defined(__FreeBSD__)
+#include <signal.h>
+#include "libgen.h"
+#endif
+
 extern struct arguments_t arguments;
 struct handler_t handlers[FC_HANDLER_MAX]=
 {
@@ -180,12 +185,24 @@
 }
 void show_event(enum handler_enum_t id, char *filename)
 {
+	struct sigaction sa;
+
+	if (arguments.fileschanged.exec_command == NULL) {
 	if (arguments.fileschanged.showaction)
 	{
 		fprintf(stdout, "%s ", handlers[id].name);
 	}
 	fprintf(stdout, "%s\n",filename);
 	fflush(stdout);
+	} else {
+		sa.sa_handler = SIG_IGN;
+		sa.sa_flags = SA_NOCLDWAIT;
+		sigemptyset(&sa.sa_mask);
+		sigaction(SIGCHLD, &sa, NULL);
+		if (!fork()) {
+			execlp(arguments.fileschanged.exec_command, arguments.fileschanged.exec_command, handlers[id].name, filename, NULL);
+		}
+	}
 	return;
 }
 int handle_created_file(FAMConnection *c, void *list, enum handler_enum_t id, char *filename)
