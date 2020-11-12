--- src/c-client/c-client.h.orig	2011-07-23 00:20:18 UTC
+++ src/c-client/c-client.h
@@ -39,7 +39,23 @@ extern "C" {
 #endif
 
 #include "mail.h"		/* primary interfaces */
+
+#ifdef __cplusplus		/* undo hacks before including OS headers */
+#undef private
+#undef and
+#undef or
+#undef not
+#endif
+
 #include "osdep.h"		/* OS-dependent routines */
+
+#ifdef __cplusplus		/* redo hacks after including OS headers */
+#define private cclientPrivate
+#define and cclientAnd
+#define or cclientOr
+#define not cclientNot
+#endif
+
 #include "rfc822.h"		/* RFC822 and MIME routines */
 #include "smtp.h"		/* SMTP sending routines */
 #include "nntp.h"		/* NNTP sending routines */
