--- ./jacal.sh.orig	Mon Dec  1 04:19:32 2003
+++ ./jacal.sh	Mon Feb 14 21:44:19 2005
@@ -92,6 +92,8 @@
      if [ -z "${SCHEME_LIBRARY_PATH}" ]; then
        if [ -d /usr/local/lib/slib/ ]; then
 	  export SCHEME_LIBRARY_PATH=/usr/local/lib/slib/
+       elif [ -d %%PREFIX%%/lib/slib/ ]; then
+	  export SCHEME_LIBRARY_PATH=%%PREFIX%%/lib/slib/
        elif [ -d /usr/share/slib/ ]; then
 	  export SCHEME_LIBRARY_PATH=/usr/share/slib/
        fi
