--- client/hobbitclient-freebsd.sh.orig	2006-07-05 07:52:22.000000000 +0200
+++ client/hobbitclient-freebsd.sh	2010-07-09 09:37:22.000000000 +0200
@@ -41,7 +41,7 @@
 echo "[netstat]"
 netstat -s
 echo "[ports]"
-(netstat -na -f inet; netstat -na -f inet6) | grep "^tcp"
+(netstat -Wna -f inet; netstat -Wna -f inet6) | grep "^tcp"
 echo "[ps]"
 # Dont use "args". "command" works also in FreeBSD 4.x.
 ps -ax -ww -o pid,ppid,user,start,state,pri,pcpu,cputime,pmem,rss,vsz,command
