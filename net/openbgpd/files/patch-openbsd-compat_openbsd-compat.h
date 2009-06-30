Index: openbsd-compat/openbsd-compat.h
===================================================================
RCS file: openbsd-compat/openbsd-compat.h
diff -N openbsd-compat/openbsd-compat.h
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ openbsd-compat/openbsd-compat.h	30 Jun 2009 06:52:12 -0000	1.2
@@ -0,0 +1,23 @@
+/*
+ * $hrs: openbgpd/openbsd-compat/openbsd-compat.h,v 1.2 2009/06/30 06:52:12 hrs Exp $
+ */
+
+#ifndef _OPENBSD_COMPAT_H
+#define _OPENBSD_COMPAT_H
+
+#define	__dead
+
+/* bgpctl/bgpctl.c */
+#include <sys/endian.h>
+#define betoh64(x)	(be64toh(x))
+
+/* bgpd/irrfilter.c */
+typedef unsigned long	ulong;
+
+/* bgpd/bgpd.c */
+#ifndef	RTLABEL_LEN	/* defined in net/pfvar.h */
+#define RTLABEL_LEN	32
+#endif
+#define RTA_LABEL	0
+
+#endif /* _OPENBSD_COMPAT_H */
