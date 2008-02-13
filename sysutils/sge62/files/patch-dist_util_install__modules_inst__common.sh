
$FreeBSD$

--- dist/util/install_modules/inst_common.sh.orig
+++ dist/util/install_modules/inst_common.sh
@@ -367,7 +367,9 @@
    missing=false
    for f in $BINFILES; do
       if [ ! -f $SGE_BIN/$f ]; then
-         missing=true
+         if [ "$f" != "qmon" ]; then
+            missing=true
+         fi
          $INFOTEXT "missing program >%s< in directory >%s<" $f $SGE_BIN
          $INFOTEXT -log "missing program >%s< in directory >%s<" $f $SGE_BIN
       fi
