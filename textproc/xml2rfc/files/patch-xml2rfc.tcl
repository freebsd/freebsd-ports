
$FreeBSD$

--- xml2rfc.tcl.orig	Mon Jun 10 04:32:34 2002
+++ xml2rfc.tcl	Thu Jul 25 21:33:22 2002
@@ -1,7 +1,7 @@
 #!/bin/sh
 # the next line restarts using the correct interpreter \
-if   test ! -z "$DISPLAY"; then exec wish "$0" "$0" "$@"; \
-elif test ! -z "$1";       then exec tclsh "$0" "$0" "$@"; \
+if   test ! -z "$DISPLAY"; then exec wish8.3 "$0" "$0" "$@"; \
+elif test ! -z "$1";       then exec tclsh8.3 "$0" "$0" "$@"; \
 else                            echo "usage: $0 filename" >&2; exit 1; fi
 
 
