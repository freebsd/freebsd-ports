--- configure.sh.orig	2023-08-16 17:12:53 UTC
+++ configure.sh
@@ -52,7 +52,7 @@ do
     --asan) asan=yes;;
     --btor2aiger) btor2aiger=yes;;
     -h|-help|--help) usage;;
-    -*) die "invalid option '$1' (try '-h')";;
+    -*) ;;
   esac
   shift
 done
