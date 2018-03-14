--- vendor/jruby/bin/jruby.sh.orig	2018-02-16 20:50:22 UTC
+++ vendor/jruby/bin/jruby.sh
@@ -26,9 +26,9 @@ progname=`basename "$0"`
 
 while [ -h "$PRG" ] ; do
   ls=`ls -ld "$PRG"`
-  link=`expr "$ls" : '.*-> \(.*\)$'`
-  if expr "$link" : '.*/.*' > /dev/null; then
-    if expr "$link" : '/' > /dev/null; then
+  link=`expr -- "$ls" : '.*-> \(.*\)$'`
+  if expr -- "$link" : '.*/.*' > /dev/null; then
+    if expr -- "$link" : '/' > /dev/null; then
       PRG="$link"
     else
       PRG="`dirname ${PRG}`/${link}"
@@ -202,7 +202,7 @@ do
      # Match -Xa.b.c=d to translate to -Da.b.c=d as a java option
      -X*)
      val=${1:2}
-     if expr "$val" : '.*[.]' > /dev/null; then
+     if expr -- "$val" : '.*[.]' > /dev/null; then
        java_args="${java_args} -Djruby.${val}"
      else
        ruby_args="${ruby_args} -X${val}"
