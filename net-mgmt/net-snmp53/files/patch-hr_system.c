--- agent/mibgroup/host/hr_system.c.orig	Sat Mar  1 05:35:13 2003
+++ agent/mibgroup/host/hr_system.c	Sun Feb  8 17:39:50 2004
@@ -280,7 +280,6 @@
     while ((utmp_p = getutent()) != NULL) {
 #ifndef UTMP_HAS_NO_TYPE
         if (utmp_p->ut_type == USER_PROCESS) {
-#endif
             /* This block of code fixes zombie user PIDs in the
                utmp/utmpx file that would otherwise be counted as a
                current user */
@@ -291,6 +290,10 @@
             }
             ++total;
         }
+#else
+	if (*utmp_p->ut_name != '~')
+            ++total;
+#endif
     }
     endutent();
     return total;
