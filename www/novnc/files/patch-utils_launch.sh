--- utils/launch.sh.orig	2017-01-12 19:36:42 UTC
+++ utils/launch.sh
@@ -69,7 +69,7 @@ done
 which netstat >/dev/null 2>&1 \
     || die "Must have netstat installed"
 
-netstat -ltn | grep -qs "${PORT} .*LISTEN" \
+netstat -a -p tcp -n | grep -qs "${PORT} .*LISTEN" \
     && die "Port ${PORT} in use. Try --listen PORT"
 
 trap "cleanup" TERM QUIT INT EXIT
