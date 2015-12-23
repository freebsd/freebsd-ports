--- src/share/poudriere/common.sh.orig	2015-11-30 17:25:11 UTC
+++ src/share/poudriere/common.sh
@@ -1847,7 +1847,7 @@ jail_stop() {
 	fi
 	msg "Umounting file systems"
 	destroyfs ${MASTERMNT} jail || :
-	rm -rfx ${MASTERMNT}/../
+	rm -rf ${MASTERMNT}/../
 	export STATUS=0
 
 	# Don't override if there is a failure to grab the last status.
