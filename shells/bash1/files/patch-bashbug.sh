--- support/bashbug.sh.race	Thu Aug 27 17:21:28 1998
+++ support/bashbug.sh	Thu Aug 27 17:23:40 1998
@@ -15,7 +15,7 @@
 PATH=/bin:/usr/bin:usr/local/bin:$PATH
 export PATH
 
-TEMP=/tmp/bashbug.$$
+TEMP=`/bin/mktemp /tmp/bashbug.XXXXXX`
 
 BUGADDR=${1-bug-bash@prep.ai.mit.edu}
 
