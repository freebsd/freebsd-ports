--- scripts/help.sh.orig	Tue Apr  6 04:24:06 2004
+++ scripts/help.sh	Mon Apr 12 18:17:30 2004
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-GNOME_BROWSER=`gconftool --get /desktop/gnome/applications/browser/exec`
+GNOME_BROWSER=`gconftool-2 --get /desktop/gnome/applications/browser/exec`
 which konqueror &> /dev/null
 [ $? = 0 ] && KONQUEROR=konqueror
 which mozilla &> /dev/null
