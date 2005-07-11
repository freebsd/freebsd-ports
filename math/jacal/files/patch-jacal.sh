--- jacal.sh.orig	Wed Jun 22 03:52:36 2005
+++ jacal.sh	Mon Jul 11 08:02:25 2005
@@ -98,6 +98,8 @@
 	  SCHEME_LIBRARY_PATH=/usr/local/lib/slib/
        elif [ -d /usr/share/slib/ ]; then
 	  SCHEME_LIBRARY_PATH=/usr/share/slib/
+       elif [ -d %%PREFIX%%/lib/slib/ ]; then
+ 	  export SCHEME_LIBRARY_PATH=%%PREFIX%%/lib/slib/
        fi
      export SCHEME_LIBRARY_PATH
      fi;;
