--- mk/make-config.sh.orig	2019-09-03 03:11:46 UTC
+++ mk/make-config.sh
@@ -1357,7 +1357,7 @@ PATH=${__PATH}
 thecmd_testandset_fail MAKE make
 make=${MAKE}
 export MAKE
-thecmd_testandset strip strip && HAVE_STRIP=1 || HAVE_STRIP=0
+thecmd_testandset strip strip
 
 # For ./mx-test.sh only
 thecmd_testandset_fail cksum cksum
