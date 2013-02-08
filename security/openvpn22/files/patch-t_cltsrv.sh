--- ./t_cltsrv.sh.orig	2011-05-16 14:21:55.000000000 +0200
+++ ./t_cltsrv.sh	2011-08-17 00:25:49.000000000 +0200
@@ -26,14 +26,14 @@
     FreeBSD)
     # FreeBSD jails map the outgoing IP to the jail IP - we need to
     # allow the real IP unless we want the test to run forever.
-    if test "`sysctl 2>/dev/null -n security.jail.jailed`" = 1 \
-    || ps -ostate= -p $$ | grep -q J; then
+    if true ; then
 	addopts="--float"
 	if test "x`ifconfig | grep inet`" = x ; then
 	    echo "###"
-	    echo "### To run the test in a FreeBSD jail, you MUST add an IP alias for the jail's IP."
+	    echo "### To run this test, it needs an inet/IP address.  Skipping."
 	    echo "###"
-	    exit 1
+	    trap 0
+	    exit 77
 	fi
     fi
     ;;
