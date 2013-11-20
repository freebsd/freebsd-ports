--- common/mkiconlinks.sh.orig	2008-09-04 17:15:42.000000000 -0500
+++ common/mkiconlinks.sh	2008-09-04 17:16:31.000000000 -0500
@@ -16,7 +16,7 @@
 while [ ! -z "$NEXTLINE" ] ; do
 
 	# Skip lines beginning with '#'
-	if [ ! "${NEXTLINE:0:1}" == '#' ]; then
+	if ! echo ${NEXTLINE} | grep -q "^#" ; then
 		#Extract first field, minus its trailing colon
 		ORIG_FILE=`echo $NEXTLINE | awk '/:/{print $1}' | sed -e 's/://'`
 
