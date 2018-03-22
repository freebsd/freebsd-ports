--- bin/build-index.sh.orig	2018-02-13 06:01:34.000000000 -0500
+++ bin/build-index.sh	2018-03-22 08:58:11.785051000 -0400
@@ -1,5 +1,5 @@
 #!/bin/bash
-export PYTHONPATH="/opt/graphite/webapp/:$PYTHONPATH"
+export PYTHONPATH="%%PREFIX%%/graphite/webapp/:$PYTHONPATH"
 BINDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
 
 ${BINDIR}/build-index
