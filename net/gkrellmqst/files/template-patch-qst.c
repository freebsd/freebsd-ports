--- qst.c.orig	Mon Jul  2 16:19:55 2001
+++ qst.c	Mon Jul  2 16:23:26 2001
@@ -25,9 +25,9 @@
 /* some defines*/
 #define MAX_MAP_NAME_LEN 64
 #define NEW_MAP "Have not talked with quake server yet"
-#define QCMD "/usr/bin/quakestat -q3s quake | awk '/^quake/ {print $2 $3;}'"
-#define SCMD "xterm -e quake3 +connect quake &"
-#define TTCMD "/usr/bin/quakestat -P -q3s quake | awk '/frags/'"
+#define QCMD "%%LOCALBASE%%/bin/quakestat -q3s quake | awk '/^quake/ {print $2 $3;}'"
+#define SCMD "%%X11BASE%%/bin/xterm -e quake3 +connect quake &"
+#define TTCMD "%%LOCALBASE%%/bin/quakestat -P -q3s quake | awk '/frags/'"
 #define CHCMD "ps ax|grep flxwm|grep -v grep>/dev/null && echo \"We've got quake!\""
 
 static Panel   *panel;
