--- agent/mibgroup/host/hr_system.c.orig	Mon Feb 23 02:29:34 2004
+++ agent/mibgroup/host/hr_system.c	Sat Apr  3 00:00:24 2004
@@ -596,6 +596,8 @@
 #ifndef UTMP_HAS_NO_TYPE
         if (utmp_p->ut_type != USER_PROCESS)
             continue;
+#else
+	if (*utmp_p->ut_name != '~')
 #endif
 #ifndef UTMP_HAS_NO_PID
             /* This block of code fixes zombie user PIDs in the
