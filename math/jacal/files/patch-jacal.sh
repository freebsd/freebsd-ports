--- jacal.sh.orig	2020-03-30 18:18:24 UTC
+++ jacal.sh
@@ -103,8 +103,8 @@ case $implementation in
 	fi
 	fi
 	if [ -z "${SCHEME_LIBRARY_PATH}" ]; then
-	    if [ -d /usr/local/lib/slib/ ]; then
-		SCHEME_LIBRARY_PATH=/usr/local/lib/slib/
+	    if [ -d %%PREFIX%%/lib/slib/ ]; then
+		SCHEME_LIBRARY_PATH=%%PREFIX%%/lib/slib/
 	    elif [ -d /usr/share/slib/ ]; then
 		SCHEME_LIBRARY_PATH=/usr/share/slib/
 	    fi
