--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ bgpd/pfkey_compat.c	8 Feb 2007 10:31:16 -0000
@@ -0,0 +1,27 @@
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
+	return (0);
+}
+
