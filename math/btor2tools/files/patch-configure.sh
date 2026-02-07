--- configure.sh.orig	2019-06-14 05:32:21 UTC
+++ configure.sh
@@ -61,7 +61,7 @@ do
     -gprof) gprof=yes;;
     -f*|-m*) if [ $flags = none ]; then flags=$1; else flags="$flags $1"; fi;;
     -h|-help|--help) usage;;
-    -*) die "invalid option '$1' (try '-h')";;
+    -*) ;;
   esac
   shift
 done
