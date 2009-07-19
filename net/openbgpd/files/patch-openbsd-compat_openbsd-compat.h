Index: openbsd-compat/openbsd-compat.h
===================================================================
RCS file: openbsd-compat/openbsd-compat.h
diff -N openbsd-compat/openbsd-compat.h
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ openbsd-compat/openbsd-compat.h	9 Jul 2009 17:22:14 -0000	1.3
@@ -0,0 +1,46 @@
+/*
+ * $hrs: openbgpd/openbsd-compat/openbsd-compat.h,v 1.3 2009/07/09 17:22:14 hrs Exp $
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
+#define SIMPLEQ_FOREACH         STAILQ_FOREACH
+#define SIMPLEQ_FIRST           STAILQ_FIRST
+#define SIMPLEQ_REMOVE_HEAD     STAILQ_REMOVE_HEAD
+#define SIMPLEQ_INSERT_TAIL     STAILQ_INSERT_TAIL
+#define SIMPLEQ_ENTRY           STAILQ_ENTRY
+#define SIMPLEQ_HEAD            STAILQ_HEAD
+#define SIMPLEQ_INIT            STAILQ_INIT
+#define SIMPLEQ_HEAD_INITIALIZER	STAILQ_HEAD_INITIALIZER
+
+/* Routing priorities used by the different routing protocols */
+#define RTP_NONE        0       /* unset priority use sane default */
+#define RTP_CONNECTED   4       /* directly connected routes */
+#define RTP_STATIC      8       /* static routes base priority */
+#define RTP_OSPF        32      /* OSPF routes */
+#define RTP_ISIS        36      /* IS-IS routes */
+#define RTP_RIP         40      /* RIP routes */
+#define RTP_BGP         48      /* BGP routes */
+#define RTP_DEFAULT     56      /* routes that have nothing set */
+#define RTP_MAX         63      /* maximum priority */
+#define RTP_ANY         64      /* any of the above */
+#define RTP_MASK        0x7f
+#define RTP_DOWN        0x80    /* route/link is down */
+
+#endif /* _OPENBSD_COMPAT_H */
