--- doc/Makedoc.sh.orig	2015-10-20 11:22:17 UTC
+++ doc/Makedoc.sh
@@ -33,10 +33,10 @@ if [ "${BUILD_ENTITY_MAP}" = "true" ]; t
     # Create a modified EntityMap.pm with entity-map location in doc
     # build temporary dir. Need to properly install entity-map there.
     mkdir $TMPDIR/Text
-    make -C ../entity-map install DESTDIR="$TMPDIR"
+    ${MAKE} -C ../entity-map install DESTDIR="$TMPDIR"
     sed < ../entity-map/EntityMap.pm.in > $TMPDIR/Text/EntityMap.pm \
-	-e 's|\@localentitymapdir\@|'${TMPDIR}'/usr/share/entity-map|g' \
-	-e 's|\@entitymapdir\@|'${TMPDIR}'/usr/share/entity-map/0.1.0|g'
+	-e 's|\@localentitymapdir\@|'${TMPDIR}${PREFIX}'/share/entity-map|g' \
+	-e 's|\@entitymapdir\@|'${TMPDIR}${PREFIX}'/share/entity-map/0.1.0|g'
 
     # Set ${TMPDIR} first in perl load path (Will put Text dir there
     # for modified EntityMap.pm), then our perl5lib
@@ -49,8 +49,8 @@ fi
 if [ "${BUILD_ISO_ENTITIES}" = "true" ]; then
     # --without-installed-iso-entities: Install iso-entities in
     # "$TMPDIR/usr" and set it as iso-entities prefix.
-    make -C ../iso-entities install DESTDIR="$TMPDIR"
-    ISOENTITIES_PREFIX="${TMPDIR}/usr"
+    ${MAKE} -C ../iso-entities install DESTDIR="$TMPDIR"
+    ISOENTITIES_PREFIX="${TMPDIR}${PREFIX}"
 else
     # --with-installed-iso-entities: Use system prefix.
     ISOENTITIES_PREFIX="${PREFIX}"
