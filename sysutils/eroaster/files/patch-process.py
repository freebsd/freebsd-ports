--- process.py.orig	Fri Jul 25 23:42:00 2003
+++ process.py	Sat Dec 20 11:47:56 2003
@@ -34,7 +34,7 @@
 #     python -c "import sys;print sys.platform"
 
 osFamily = {}
-osFamily[OSTYPEBSD] = ["freebsd4", "bsdos4"]
+osFamily[OSTYPEBSD] = ["freebsd4", "freebsd5", "bsdos4"]
 osFamily[OSTYPESYSV] = ["linux-i386", "linux2" ]
 osFamily[OSTYPESUNOSUCB] = ["sunos5"]
 
@@ -45,6 +45,8 @@
 osPsParam[OSTYPESUNOSUCB] = "-l %s"
 
 osPsProcessListParam = {}
+osPsProcessListParam["freebsd4"] = "-ax"
+osPsProcessListParam["freebsd5"] = "-ax"
 osPsProcessListParam["sunos5"] = "-ef"
 osPsProcessListParam["linux2"] = "ax"
 osPsProcessListParam[OSTYPEUNKNOWN] = "ax"
@@ -98,7 +100,7 @@
             elif (column == "STAT"):
                 # Status: S, W, N, R, L, <
                 strRegExp = "%s([SWNRL<]+) +" % strRegExp
-            elif (column == "TTY"):
+            elif ((column == "TTY") or (column == "TT")):
                 # TTY: ?, pty/1, console
                 strRegExp = "%s(\?|[\w/]+\d*) +" % strRegExp
             elif ((column == "CMD") or (column == "COMMAND")):
