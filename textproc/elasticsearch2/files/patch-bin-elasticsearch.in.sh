--- bin/elasticsearch.in.sh.orig	2015-11-19 16:02:28.386051810 -0500
+++ bin/elasticsearch.in.sh	2015-11-19 16:02:56.618049877 -0500
@@ -1,5 +1,19 @@
 #!/bin/sh
 
+if [ `uname -o` == "FreeBSD" ]; then
+	. /etc/rc.subr
+	load_rc_config elasticsearch
+	ES_MIN_MEM=${elasticsearch_min_mem}
+	ES_MAX_MEM=${elasticsearch_max_mem}
+	ES_HEAP_NEW_SIZE=${elasticsearch_heap_newsize}
+	ES_DIRECT_SIZE=${elasticsearch_direct_size}
+	ES_USE_IPV4=${elasticsearch_use_ipv4}
+	ES_GC_OPTS=${elasticsearch_gc_opts}
+	ES_GC_LOG_FILE=${elasticsearch_gc_logfile}
+	JAVA_OPTS="$JAVA_OPTS -Des.path.conf=${elasticsearch_config:="%%PREFIX%%/etc/elasticsearch"}"
+	JAVA_OPTS="$JAVA_OPTS -Des.path.scripts=${elasticsearch_scripts:="%%PREFIX%%/libexec/elasticsearch"}"
+fi
+
 # check in case a user was using this mechanism
 if [ "x$ES_CLASSPATH" != "x" ]; then
     cat >&2 << EOF
