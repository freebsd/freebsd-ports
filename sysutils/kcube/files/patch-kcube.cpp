--- kcube/kcube.cpp.orig	Thu Feb 13 22:12:49 2003
+++ kcube/kcube.cpp	Wed Feb 25 03:59:17 2004
@@ -33,9 +33,19 @@
 #include <qslider.h>
 
 #include <stdio.h>
+#include <unistd.h>
+#include <fcntl.h>
+
+#include <nlist.h>
 
 #include "kcube.h"
 
+struct nlist    nl[] = {
+#define X_CP_TIME   0
+    { "_cp_time" },
+    { "" },
+};
+
 extern "C"
 {
 	KPanelApplet* init( QWidget *parent, const QString configFile)
@@ -64,7 +74,7 @@
 
 	// timer
 	cpu_timer = new QTimer();
-	cpu_timer->start(500, false);
+	cpu_timer->start(1000, false);
 	connect (cpu_timer, SIGNAL ( timeout() ), this, SLOT ( cpu_timer_event() ) );
 	draw_timer = new QTimer();
 	draw_timer->start(50, false);
@@ -82,6 +92,7 @@
 	prefform = new PrefForm(this);
 	prefform->setFixedSize( prefform->width(), prefform->height() );
 	loadConfig();
+
 }
 
 Kcube::~Kcube()
@@ -119,14 +130,42 @@
 int Kcube::calc_cpu_total()
 {
 	int 	use_nice = 0, t=0;
-	int 	total, used;
+	long 	total, used;
 	char 	cpuid[6];
-	int 	cpu,nice,system,idle;
+	long 	cpu,nice,system,idle;
+#ifdef Q_OS_BSD4
+    static int name2oid[2] = { 0, 3 };
+    static int oidCpuTime[CTL_MAXNAME + 2];
+    static size_t oidCpuTimeLen = sizeof(oidCpuTime);
+    long cpuTime[CPUSTATES];
+    size_t cpuTimeLen = sizeof(cpuTime);
+    static char *name = "kern.cp_time";
+    static int initialized = 0;
+#endif
 
+#ifdef Q_OS_LINUX
 	FILE *fp;
 	fp = fopen("/proc/stat","rt");
 	fscanf(fp,"%s %d %d %d %d",cpuid,&cpu,&nice,&system,&idle);
 	fclose(fp);
+#endif
+
+#ifdef Q_OS_BSD4
+	if (! initialized) {
+		if (sysctl(name2oid, 2, oidCpuTime, &oidCpuTimeLen, name, strlen(name)) < 0)
+			return 0;
+		oidCpuTimeLen /= sizeof(int);
+		initialized = 1;
+	}
+
+	if (sysctl(oidCpuTime, oidCpuTimeLen, cpuTime, &cpuTimeLen, 0, 0) < 0)
+		return 0;
+
+	idle = cpuTime[CP_IDLE];
+	cpu = cpuTime[CP_USER];
+	nice = cpuTime[CP_NICE];
+	system = cpuTime[CP_SYS];
+#endif
 
 	used 	= cpu + system + nice;
 	total 	= used + idle + (1-use_nice)*nice;
@@ -148,7 +187,7 @@
 	if ( load > prefform->high_color_cpu->text().toInt() ) setColors("high");
 	else setColors("low");
 		
-	draw_timer->changeInterval( 51 - load/2 );
+	draw_timer->changeInterval( 61 - load/2 );
 	label_load->setText( QString("%1%").arg(load) );
 }
 
