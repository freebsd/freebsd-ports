--- agent/mibgroup/host/hr_system.c.orig	Fri Nov 14 14:45:55 2003
+++ agent/mibgroup/host/hr_system.c	Fri Nov 14 14:46:01 2003
@@ -276,11 +276,10 @@
     struct utmp    *utmp_p;
 #endif
 
+#ifndef UTMP_HAS_NO_TYPE
     setutent();
     while ((utmp_p = getutent()) != NULL) {
-#ifndef UTMP_HAS_NO_TYPE
         if (utmp_p->ut_type == USER_PROCESS) {
-#endif
             /* This block of code fixes zombie user PIDs in the
                utmp/utmpx file that would otherwise be counted as a
                current user */
@@ -293,6 +292,7 @@
         }
     }
     endutent();
+#endif
     return total;
 }
 
