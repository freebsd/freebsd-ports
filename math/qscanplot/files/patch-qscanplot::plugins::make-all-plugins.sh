
$FreeBSD$

--- qscanplot/plugins/make-all-plugins.sh	2002/04/23 09:48:36	1.1
+++ qscanplot/plugins/make-all-plugins.sh	2002/04/23 09:51:37
@@ -4,5 +4,5 @@
 
 for i in `cat FUNCTIONS`; do
   echo ; echo \# Generating plugin for function \"$i\":
-  . make-plugin.sh $i
+  ./make-plugin.sh $i
 done
