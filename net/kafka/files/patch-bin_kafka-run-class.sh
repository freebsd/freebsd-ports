--- bin/kafka-run-class.sh.orig	2017-07-14 16:36:53 UTC
+++ bin/kafka-run-class.sh
@@ -125,12 +125,7 @@ do
 done
 
 # classpath addition for release
-for file in "$base_dir"/libs/*;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
+CLASSPATH="$CLASSPATH":"$base_dir"/libs/*
 
 for file in "$base_dir"/core/build/libs/kafka_${SCALA_BINARY_VERSION}*.jar;
 do
