--- doc/config.sh.orig	Tue Nov  1 06:36:57 1994
+++ doc/config.sh	Sun Jan  9 09:30:03 2000
@@ -11,11 +11,11 @@
 # (modify these lines to suit your system)
 #
 # the location of inetd on your system (usually /etc/inetd)
-MINETD=/etc/inetd
+MINETD=/usr/sbin/inetd
 # the location of the inetd configuration file (usually /etc/inetd.conf)
 MINETDCONFIG=/etc/inetd.conf
 # the location of nntpd following installation (usually /etc/nntpd)
-MNNTPD=/etc/nntpd
+MNNTPD=/usr/local/sbin/nntpd
 # the location of the hosts file (usually /etc/hosts)
 MHOSTFILE=/etc/hosts
 # the location of the services file (usually /etc/services)
@@ -23,12 +23,12 @@
 # the location of the networks file (usually /etc/networks)
 MNETWORKFILE=/etc/networks
 # The location of the news spool directory (usually /usr/spool/news)
-MNEWSSPOOL=/usr/spool/news
+MNEWSSPOOL=/var/news
 # The location of the news library directory (usually /usr/lib/news)
-MNEWSLIB=/usr/lib/news
+MNEWSLIB=/usr/local/news/lib
 # The location of the file containing the name of the nntp server machine
 # (usually /usr/local/lib/rn/server)
-MSERVERFILE=/usr/local/lib/rn/server
+MSERVERFILE=/usr/local/etc/nntpserver
 # The location of rn's local library (usually /usr/local/lib/rn)
 MRNLIB=/usr/local/lib/rn
 #
