--- interfaces/maple/lb-maple-path.sh.orig	2021-12-14 10:16:03 UTC
+++ interfaces/maple/lb-maple-path.sh
@@ -1,7 +1,7 @@
-#!/usr/bin/sh
+#! /bin/sh
 
 if test -r "lb-maple.mpl.bak"; then
     mv lb-maple.mpl.bak lb-maple.mpl
 fi
 
-sed -e "s|lbpathvalue|lbpath:=\"$1\";|" -i.bak lb-maple.mpl  
\ No newline at end of file
+sed -e "s|lbpathvalue|lbpath:=\"$1\";|" -i.bak lb-maple.mpl  
