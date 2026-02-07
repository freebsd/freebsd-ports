--- client/xymonclient-freebsd.sh.orig	2015-12-16 15:13:03 UTC
+++ client/xymonclient-freebsd.sh
@@ -55,6 +55,8 @@ ps -axd -ww -o pid,ppid,user,start,state,pri,pcpu,cput
 echo "[ps]"
 # Don't use "args". "command" works also in FreeBSD 4.x.
 ps -axd -ww -o pid,ppid,user,start,state,pri,pcpu,cputime,pmem,rss,vsz,command
+echo "[pkg"]
+pkg query %n-%v
 
 # $TOP must be set, the install utility should do that for us if it exists.
 if test "$TOP" != ""
