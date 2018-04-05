--- ltmain.sh.orig	2018-04-04 21:26:22.534684000 -0400
+++ ltmain.sh	2018-04-04 21:26:32.219631000 -0400
@@ -1288,6 +1288,11 @@
 	continue
 	;;
 
+      -fuse-ld=*)
+        compiler_flags="$compiler_flags $qarg"
+        continue
+        ;;
+
       -inst-prefix-dir)
 	prev=inst_prefix
 	continue
