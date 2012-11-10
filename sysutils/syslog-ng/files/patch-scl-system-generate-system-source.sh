--- scl/system/generate-system-source.sh.orig	2012-08-15 01:06:08.000000000 -0700
+++ scl/system/generate-system-source.sh	2012-11-09 19:42:06.000000000 -0800
@@ -74,7 +74,17 @@
 		cat <<EOF
 unix-dgram("/var/run/log");
 unix-dgram("/var/run/logpriv" perm(0600));
-file("/dev/klog" follow-freq(0) program-override("kernel") flags(no-parse));
+EOF
+                case "$osversion" in
+                        7.*|8.*|9.0*)
+                                ffreq=1
+                                ;;
+                        *)
+                                ffreq=0
+                                ;;
+                esac
+                cat <<EOF
+file("/dev/klog" follow-freq($ffreq) program-override("kernel") flags(no-parse));
 EOF
 		;;
 	GNU/kFreeBSD)
