--- MasterSrv/install.sh.orig	2012-10-10 23:19:06.000000000 +0200
+++ MasterSrv/install.sh	2012-10-18 15:53:05.000000000 +0200
@@ -42,7 +42,6 @@
 $DEBUG /bin/grep -q ^_neubot /etc/group || $DEBUG /usr/sbin/groupadd -r _neubot
 $DEBUG /bin/grep -q ^_neubot /etc/passwd || \
        $DEBUG /usr/sbin/useradd -r -d/ -g_neubot -s/sbin/nologin _neubot
-$DEBUG sed -i 's/@USER@/_neubot/g' /home/simone/neubot/neubot/system_posix.py
 $DEBUG $INSTALL -d /var/lib/neubot
 
 $DEBUG $INSTALL -d /usr/local/share/GeoIP
