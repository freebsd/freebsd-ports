--- src/share/poudriere/ports.sh.orig	2015-12-04 16:38:46 UTC
+++ src/share/poudriere/ports.sh
@@ -173,7 +173,7 @@ else
 	none);;
 	*) usage;;
 	esac
-	SVN_FULLURL=${proto}://${SVN_HOST}/base
+	SVN_FULLURL=${proto}://${SVN_HOST}/ports
 	if [ -n "${GIT_URL}" ]; then
 		GIT_FULLURL=${GIT_URL}
 	else
