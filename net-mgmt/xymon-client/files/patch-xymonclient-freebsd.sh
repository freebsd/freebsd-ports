--- client/xymonclient-freebsd.sh.orig	2010-11-14 18:21:19.000000000 +0100
+++ client/xymonclient-freebsd.sh	2011-03-31 06:52:18.000000000 +0200
@@ -43,7 +43,7 @@
 echo "[netstat]"
 netstat -s
 echo "[ports]"
-(netstat -na -f inet; netstat -na -f inet6) | grep "^tcp"
+(netstat -Wna -f inet; netstat -Wna -f inet6) | grep "^tcp"
 echo "[ps]"
 # Dont use "args". "command" works also in FreeBSD 4.x.
 ps -ax -ww -o pid,ppid,user,start,state,pri,pcpu,cputime,pmem,rss,vsz,command
