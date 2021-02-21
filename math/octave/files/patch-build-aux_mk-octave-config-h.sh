--- build-aux/mk-octave-config-h.sh.orig	2020-11-26 18:20:44 UTC
+++ build-aux/mk-octave-config-h.sh
@@ -29,7 +29,7 @@
 # autoconf-generated config.h file.  See the notes at the top of the
 # generated octave-config.h file for more details.
 
-SED=${SED:-sed}
+SED=gsed
 
 if [ $# -ne 1 ]; then
   echo "usage: mk-octave-config-h.sh CONFIG-FILE" 1>&2
