--- ./clients/lcdproc/machine_FreeBSD.c.orig	Sat Apr 14 16:38:15 2007
+++ ./clients/lcdproc/machine_FreeBSD.c	Sun Aug 26 23:21:56 2007
@@ -45,16 +45,22 @@
 #include <sys/mount.h>
 #include <sys/time.h>
 #include <sys/user.h>
-#include <machine/apm_bios.h>
 #include <kvm.h>
 #include <errno.h>
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_mib.h>
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
+#ifdef HAVE_MACHINE_APM_BIOS_H
+# include <machine/apm_bios.h>
+#endif
+
 #include "main.h"
 #include "machine.h"
-#include "config.h"
 #include "shared/LL.h"
 
 static int pageshift;
@@ -86,13 +92,14 @@
 
 int machine_get_battstat(int *acstat, int *battflag, int *percent)
 {
-	int apmd;
-	struct apm_info aip;
-
 	*acstat   = LCDP_AC_ON;
 	*battflag = LCDP_BATT_ABSENT;
 	*percent  = 100;
 
+#ifdef HAVE_MACHINE_APM_BIOS_H
+	int apmd;
+	struct apm_info aip;
+
 	if ((apmd = open("/dev/apm", O_RDONLY)) == -1)
 	{
 		perror("get_battstat_open");
@@ -142,6 +149,7 @@
 		*percent = -1;
 
 	close(apmd);
+#endif
 
 	return(TRUE);
 }
@@ -197,7 +205,7 @@
 	static load_type last_load = { 0, 0, 0, 0, 0 };
 	static load_type last_ret_load;
 	load_type load;
-	u_int32_t cp_time[CPUSTATES];
+	long cp_time[CPUSTATES];
 	size_t size;
 
 	size = sizeof(cp_time);
