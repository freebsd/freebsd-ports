--- src/hwcap.c.orig	2020-07-13 17:14:55 UTC
+++ src/hwcap.c
@@ -14,13 +14,19 @@
 #ifdef HAVE_SYS_AUXV_H
 #	include <sys/auxv.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#else
 #include <sys/utsname.h>
-
-#ifndef __linux__
-#	error "Platform not supported (only Linux supported at the moment)"
 #endif
+
 #ifndef HAVE_GETAUXVAL
-#	error "Platform not supported (no getauxval())"
+static unsigned long getauxval(int aux)
+{
+	unsigned long auxval = 0;
+	elf_aux_info(aux, &auxval, sizeof(auxval));
+	return auxval;
+}
 #endif
 
 #include "hwcap.h"
@@ -53,9 +59,21 @@ unsigned long get_hwcap2()
  */
 char* get_uname_machine()
 {
+#ifdef __FreeBSD__
+	/**
+	 * Contrary to this code expectation, on FreeBSD/arm, `uname -m'
+	 * is always `arm', so we return more unique `uname -p' instead.
+	 */
+	int mib[] = { CTL_HW, HW_MACHINE_ARCH };
+	static char buf[48];
+	size_t len = sizeof(buf);
+	if (sysctl(mib, 2, &buf, &len, NULL, 0) == 0)
+		return buf;
+#else
 	static struct utsname uname_res;
 	if (uname(&uname_res) != -1)
 		return uname_res.machine;
+#endif
 	else
 		return NULL;
 }
