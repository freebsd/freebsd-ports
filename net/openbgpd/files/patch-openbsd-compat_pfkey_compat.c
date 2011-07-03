Index: openbsd-compat/pfkey_compat.c
===================================================================
RCS file: openbsd-compat/pfkey_compat.c
diff -N openbsd-compat/pfkey_compat.c
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ openbsd-compat/pfkey_compat.c	3 Jul 2011 11:18:30 -0000	1.3
@@ -0,0 +1,32 @@
+#include "bgpd.h"
+#include "session.h"
+
+int
+pfkey_establish(struct peer *p)
+{
+	if (p->conf.auth.method)
+		return (-1);
+	return (0);
+}
+
+int
+pfkey_remove(struct peer *p)
+{
+        if (p->conf.auth.method)
+                return (-1);
+        return (0);
+}
+
+int
+pfkey_init(struct bgpd_sysdep *sysdep)
+{
+	log_warnx("no kernel support for PF_KEY");
+	sysdep->no_pfkey = 1;
+	return (-1);
+}
+
+int
+pfkey_read(int sd, struct sadb_msg *h)
+{
+	return (1);
+}
