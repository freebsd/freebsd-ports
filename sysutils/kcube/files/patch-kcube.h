--- kcube/kcube.h.orig	Thu Feb 13 19:25:29 2003
+++ kcube/kcube.h	Wed Feb 25 03:59:17 2004
@@ -37,6 +37,18 @@
 
 #include "PrefForm.h"
 
+#ifdef Q_OS_BSD4
+#include <sys/param.h>
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
+#include <sys/dkstat.h>
+#endif
+#include <sys/sysctl.h>
+#include <string.h>
+#include <kvm.h>
+#endif
+
 class Kcube : public KPanelApplet
 {
 Q_OBJECT
