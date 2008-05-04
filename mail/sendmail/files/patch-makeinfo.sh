--- cf/sh/makeinfo.sh.orig	1999-02-07 08:26:25.000000000 +0100
+++ cf/sh/makeinfo.sh	2008-05-04 11:55:42.000000000 +0200
@@ -52,7 +52,7 @@
 else
 	host=`uname -n`
 fi
-echo '#####' built by $user@$host on `date`
+echo '#####' built by $user@$host on `LC_TIME=C date`
 echo '#####' in `pwd` | sed 's/\/tmp_mnt//'
 echo '#####' using $1 as configuration include directory | sed 's/\/tmp_mnt//'
 echo "define(\`__HOST__', $host)dnl"
