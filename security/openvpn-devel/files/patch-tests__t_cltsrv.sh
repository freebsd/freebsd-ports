--- tests/t_cltsrv.sh.orig	2016-08-23 13:10:22 UTC
+++ tests/t_cltsrv.sh
@@ -1,7 +1,7 @@
 #! /bin/sh
 #
 # t_cltsrv.sh - script to test OpenVPN's crypto loopback
-# Copyright (C) 2005, 2006, 2008  Matthias Andree
+# Copyright (C) 2005 - 2014  Matthias Andree
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -22,8 +22,9 @@ set -e
 srcdir="${srcdir:-.}"
 top_srcdir="${top_srcdir:-..}"
 top_builddir="${top_builddir:-..}"
-trap "rm -f log.$$ log.$$.signal ; trap 0 ; exit 77" 1 2 15
-trap "rm -f log.$$ log.$$.signal ; exit 1" 0 3
+root="${top_srcdir}/sample"
+trap "rm -f ${root}/sample-config-files/loopback-*.test log.$$ log.$$.signal ; trap 0 ; exit 77" 1 2 15
+trap "a=\$? ; rm -f ${root}/sample-config-files/loopback-*.test log.$$ log.$$.signal ; test \$a = 0 && exit 1 || exit \$a" 0 3
 addopts=
 case `uname -s` in
     FreeBSD)
@@ -45,18 +46,38 @@ esac
 # make sure that the --down script is executable -- fail (rather than
 # skip) test if it isn't.
 downscript="../tests/t_cltsrv-down.sh"
-root="${top_srcdir}/sample"
 test -x "${root}/${downscript}" || chmod +x "${root}/${downscript}" || { echo >&2 "${root}/${downscript} is not executable, failing." ; exit 1 ; }
 echo "The following test will take about two minutes." >&2
 echo "If the addresses are in use, this test will retry up to two times." >&2
 
+set -- $(ifconfig lo0 | grep -E '\<inet' | head -n1)
+add=
+if [ "x$1$2" = "x" ] ; then
+    echo >&2 "### NO ADDRESSES ON LOOPBACK INTERFACE lo0, SKIPPING TEST ###"
+    exit 77
+fi
+if [ "inet6" = "$1" ] ; then
+    add='proto udp6 '
+fi
+for i in server client ; do
+    sed -e "s/localhost/$2/" -e "/^remote /a\\
+$add" ${root}/sample-config-files/loopback-$i \
+    >${root}/sample-config-files/loopback-$i.test
+done
+
 # go
 success=0
 for i in 1 2 3 ; do
   set +e
   (
-  "${top_builddir}/src/openvpn/openvpn" --script-security 2 --cd "${root}" ${addopts} --setenv role srv --down "${downscript}" --tls-exit --ping-exit 180 --config "sample-config-files/loopback-server" &
-  "${top_builddir}/src/openvpn/openvpn" --script-security 2 --cd "${top_srcdir}/sample" ${addopts} --setenv role clt --down "${downscript}" --tls-exit --ping-exit 180 --config "sample-config-files/loopback-client"
+  "${top_builddir}/src/openvpn/openvpn" --script-security 2 \
+      --cd "${root}" ${addopts} --setenv role srv \
+      --down "${downscript}" --tls-exit --ping-exit 180 \
+      --config "sample-config-files/loopback-server.test" &
+  "${top_builddir}/src/openvpn/openvpn" --script-security 2 \
+      --cd "${top_srcdir}/sample" ${addopts} --setenv role clt \
+      --down "${downscript}" --tls-exit --ping-exit 180 \
+      --config "sample-config-files/loopback-client.test"
   ) 3>log.$$.signal >log.$$ 2>&1
   e1=$?
   wait $!
