--- a/softhddev.c
+++ b/softhddev.c
@@ -22,6 +22,9 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <signal.h>
+#endif
 #include <fcntl.h>
 
 #include <stdio.h>
@@ -2212,6 +2215,11 @@ int ProcessArgs(int argc, char *const ar
     //
     //	Parse arguments.
     //
+#ifdef __FreeBSD__
+    if (!strcmp(*argv, "softhddevice"))
+	++argv, --argc;
+#endif
+
     for (;;) {
 	switch (getopt(argc, argv, "-a:c:d:fg:p:sv:w:x")) {
 	    case 'a':			// audio device for pcm
@@ -2294,7 +2302,11 @@ int ProcessArgs(int argc, char *const ar
 
 #define XSERVER_MAX_ARGS 512		///< how many arguments support
 
+#ifndef __FreeBSD__
 static const char *X11Server = "/usr/bin/X";	///< default x11 server
+#else
+static const char *X11Server = LOCALBASE "/bin/X";	///< default x11 server
+#endif
 static const char *X11ServerArguments;	///< default command arguments
 static pid_t X11ServerPid;		///< x11 server pid
 
@@ -2338,7 +2350,12 @@ static void StartXServer(void)
     if ((sval = X11ServerArguments)) {
 	char *s;
 
+#ifndef __FreeBSD__
 	s = buf = strdupa(sval);
+#else
+	s = buf = alloca(strlen(sval) + 1);
+	strcpy(buf, sval);
+#endif
 	while ((sval = strsep(&s, " \t"))) {
 	    args[argn++] = sval;
 
