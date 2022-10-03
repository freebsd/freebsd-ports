--- devctl_jail.c.orig	2019-05-21 13:00:05 UTC
+++ devctl_jail.c
@@ -34,10 +34,10 @@
 
 #include <sys/cdefs.h>
 #include <sys/types.h>
+#include <sys/param.h>  /* defines used in kernel.h */
 #include <sys/module.h>
 #include <sys/systm.h>  /* uprintf */
 #include <sys/errno.h>
-#include <sys/param.h>  /* defines used in kernel.h */
 #include <sys/kernel.h> /* types used in module initialization */
 #include <sys/jail.h>
 #include <sys/proc.h>
@@ -73,7 +73,7 @@ devctl_jail_prison_create(void *obj, void *data __unus
   sbuf_new(&sb, buf, DEVCTL_JAIL_LOGSIZE, SBUF_FIXEDLEN);
   sbuf_printf(&sb, "jid=%d", pr->pr_id);
   sbuf_finish(&sb);
-  devctl_notify_f("kernel", "jail", "created", sbuf_data(&sb), M_NOWAIT);
+  devctl_notify("kernel", "jail", "created", sbuf_data(&sb));
   sbuf_delete(&sb);
   free(buf, M_DEVCTL_JAIL);
   return (0);
@@ -117,7 +117,7 @@ devctl_jail_prison_set(void *obj, void *data)
   }
 
   sbuf_finish(&sb);
-  devctl_notify_f("kernel", "jail", "updated", sbuf_data(&sb), M_NOWAIT);
+  devctl_notify("kernel", "jail", "updated", sbuf_data(&sb));
   sbuf_delete(&sb);
   free(buf, M_DEVCTL_JAIL);
   return (0);
@@ -143,7 +143,7 @@ devctl_jail_prison_remove(void *obj, void *data __unus
   sbuf_new(&sb, buf, DEVCTL_JAIL_LOGSIZE, SBUF_FIXEDLEN);
   sbuf_printf(&sb, "jid=%d", pr->pr_id);
   sbuf_finish(&sb);
-  devctl_notify_f("kernel", "jail", "removed", sbuf_data(&sb), M_NOWAIT);
+  devctl_notify("kernel", "jail", "removed", sbuf_data(&sb));
   sbuf_delete(&sb);
   free(buf, M_DEVCTL_JAIL);
   return (0);
@@ -165,7 +165,7 @@ devctl_jail_prison_attach(void *obj, void *data __unus
   sbuf_new(&sb, buf, DEVCTL_JAIL_LOGSIZE, SBUF_FIXEDLEN);
   sbuf_printf(&sb, "jid=%d pid=%d", pr->pr_id, td->td_proc->p_pid);
   sbuf_finish(&sb);
-  devctl_notify_f("kernel", "jail", "attached", sbuf_data(&sb), M_NOWAIT);
+  devctl_notify("kernel", "jail", "attached", sbuf_data(&sb));
   sbuf_delete(&sb);
   free(buf, M_DEVCTL_JAIL);
   return (0);
