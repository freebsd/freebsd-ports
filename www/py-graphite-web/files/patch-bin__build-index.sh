--- bin/build-index.sh.orig	2018-04-23 17:11:55 UTC
+++ bin/build-index.sh
@@ -1,5 +1,5 @@
 #!/usr/local/bin/bash
-export PYTHONPATH="/opt/graphite/webapp/:$PYTHONPATH"
+export PYTHONPATH="%%PREFIX%%/graphite/webapp/:$PYTHONPATH"
 BINDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
 
 ${BINDIR}/build-index
