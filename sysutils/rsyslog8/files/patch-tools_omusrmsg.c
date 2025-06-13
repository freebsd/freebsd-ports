# This is https://github.com/rgerhards/rsyslog/commit/72b8bcc05318f0a72ec828d1a5329fa98c021eb8
# slightly reformatted for application by the ports.

--- tools/omusrmsg.c.orig	2025-06-10 09:49:19 UTC
+++ tools/omusrmsg.c
@@ -8,7 +8,7 @@
  * File begun on 2007-07-20 by RGerhards (extracted from syslogd.c, which at the
  * time of the fork from sysklogd was under BSD license)
  *
- * Copyright 2007-2018 Adiscon GmbH.
+ * Copyright 2007-2025 Adiscon GmbH.
  *
  * This file is part of rsyslog.
  *
@@ -35,14 +35,27 @@
 #include <signal.h>
 #include <ctype.h>
 #include <sys/param.h>
-#ifdef HAVE_UTMP_H
-#  include <utmp.h>
-#  define STRUCTUTMP struct utmp
-#  define UTNAME ut_name
-#else
-#  include <utmpx.h>
-#  define STRUCTUTMP struct utmpx
-#  define UTNAME ut_user
+#ifdef HAVE_UTMPX_H
+# include <utmpx.h>
+# define STRUCTUTMP struct utmpx
+# define UTNAME ut_user
+# define setutent setutxent
+# define getutent getutxent
+# define endutent endutxent
+# ifndef UT_LINESIZE
+/* __UT_LINESIZE for glibc; _UTX_LINESIZE common on Solaris */
+#  ifdef __UT_LINESIZE
+#   define UT_LINESIZE __UT_LINESIZE
+#  elif defined(_UTX_LINESIZE)
+#   define UT_LINESIZE _UTX_LINESIZE
+#  else /* method of last resort */
+#   define UT_LINESIZE 32
+#  endif
+# endif
+#elif defined(HAVE_UTMP_H)
+# include <utmp.h>
+# define STRUCTUTMP struct utmp
+# define UTNAME ut_name
 #endif
 #include <unistd.h>
 #include <sys/uio.h>
@@ -173,9 +186,15 @@ ENDdbgPrintInstInfo
 #ifdef OS_BSD
 /* Since version 900007, FreeBSD has a POSIX compliant <utmpx.h> */
 #if defined(__FreeBSD__) && (__FreeBSD_version >= 900007)
-#  define setutent(void) setutxent(void)
-#  define getutent(void) getutxent(void)
-#  define endutent(void) endutxent(void)
+#  ifndef setutent
+#    define setutent() setutxent()
+#  endif
+#  ifndef getutent
+#    define getutent() getutxent()
+#  endif
+#  ifndef endutent
+#    define endutent() endutxent()
+#  endif
 #else
 static FILE *BSD_uf = NULL;
 void setutent(void)
