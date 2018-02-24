--- build-aux/mk-octave-config-h.sh.orig	2017-02-22 18:01:55 UTC
+++ build-aux/mk-octave-config-h.sh
@@ -22,7 +22,7 @@
 # autoconf-generated config.h file.  See the notes at the top of the
 # generated octave-config.h file for more details.
 
-SED=${SED:-sed}
+SED=gsed
 
 if [ $# -ne 1 ]; then
   echo "usage: mk-octave-config-h.sh CONFIG-FILE" 1>&2
