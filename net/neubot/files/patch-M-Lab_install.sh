--- M-Lab/install.sh	2012-10-18 15:47:46.000000000 +0200
+++ M-Lab/install.sh.orig	2012-10-10 23:19:06.000000000 +0200
@@ -34,3 +34,4 @@
 $DEBUG grep -q ^_neubot /etc/group || $DEBUG /usr/sbin/groupadd -r _neubot
 $DEBUG grep -q ^_neubot /etc/passwd || \
        $DEBUG /usr/sbin/useradd -r -d/ -g_neubot -s/sbin/nologin _neubot
+$DEBUG sed -i 's/@USER@/_neubot/g' $HOME/neubot/neubot/system_posix.py
