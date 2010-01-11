Index: gkfreq.c
diff -u -p gkfreq.c.orig gkfreq.c
--- gkfreq.c.orig	Fri Aug 12 01:53:22 2005
+++ gkfreq.c	Wed Nov  9 02:28:35 2005
@@ -10,6 +10,9 @@
 #include <sys/time.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 
 #define	CONFIG_NAME	"gkfreq"
 #define	STYLE_NAME	"gkfreq"
@@ -18,18 +21,34 @@ static GkrellmMonitor	*monitor;
 static GkrellmPanel	*panel;
 static GkrellmDecal	*decal_text1;
 static gint	style_id;
+#ifdef __FreeBSD__
+static int	oid_freq[CTL_MAXNAME + 2];
+static size_t	oid_freq_len = 0;
+#endif
 
 
+#if 0
 __inline__ unsigned long long int rdtsc()
 {
 	unsigned long long int x;
 	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
 	return x;
 }
+#endif
 
 static
 void read_MHz(char* buffer_, size_t bufsz_)
 {
+#ifdef __FreeBSD__
+	int freq;
+	size_t len = sizeof(freq);
+
+	if (oid_freq_len <= 0 ||
+	    sysctl(oid_freq, oid_freq_len, &freq, &len, 0, 0) < 0)
+		snprintf(buffer_, bufsz_, "n/a MHz");
+	else
+		snprintf(buffer_, bufsz_, "%d MHz", freq);
+#else
    FILE *f;
    if ( (f = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq", "r")) == NULL) {
 
@@ -41,6 +60,7 @@ void read_MHz(char* buffer_, size_t bufs
        snprintf(buffer_, bufsz_, "%d MHz", i/1000 );
        fclose(f);
    }
+#endif
 }
 
 static gint
@@ -103,6 +123,12 @@ create_plugin(GtkWidget *vbox, gint firs
 	if (first_create)
 	    g_signal_connect(G_OBJECT (panel->drawing_area), "expose_event",
     	        G_CALLBACK (panel_expose_event), NULL);
+
+#ifdef __FreeBSD__
+	oid_freq_len = sizeof(oid_freq);
+	if (sysctlnametomib("dev.cpu.0.freq", oid_freq, &oid_freq_len) < 0)
+		oid_freq_len = 0;
+#endif
 }
 
 
