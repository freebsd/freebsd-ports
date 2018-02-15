--- bin/elasticsearch.in.sh.orig	2016-11-24 10:05:27 UTC
+++ bin/elasticsearch.in.sh
@@ -1,5 +1,19 @@
 #!/bin/bash
 
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
+	ES_JAVA_OPTS="$ES_JAVA_OPTS -Des.path.conf=${elasticsearch_config:="/usr/local/etc/elasticsearch"}"
+	PATH=${PATH}:/usr/local/bin
+fi
+
 # check in case a user was using this mechanism
 if [ "x$ES_CLASSPATH" != "x" ]; then
     cat >&2 << EOF
