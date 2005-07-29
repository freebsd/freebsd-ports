
$FreeBSD$

--- dist/util/install_modules/inst_common.sh.orig
+++ dist/util/install_modules/inst_common.sh
@@ -1169,8 +1169,9 @@
       Execute cp $SGE_STARTUP_FILE $RC_PREFIX/$STARTUP_FILE_NAME
       /usr/sbin/update-rc.d $STARTUP_FILE_NAME defaults 95 03
    elif [ "$RC_FILE" = "freebsd" ]; then
-      echo  cp $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
-      Execute cp $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
+# XXX: should add the rc.subr script to the main distribution
+#      echo  cp $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
+#      Execute cp $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
    elif [ "$RC_FILE" = "SGE" ]; then
       echo  mkdir -p "$RC_PREFIX/$RC_DIR"
       Execute mkdir -p "$RC_PREFIX/$RC_DIR"
@@ -1902,8 +1903,8 @@
       Execute rm $SGE_STARTUP_FILE $RC_PREFIX/$STARTUP_FILE_NAME
       /sbin/insserv -r $RC_PREFIX/$STARTUP_FILE_NAME
    elif [ "$RC_FILE" = "freebsd" ]; then
-      echo  rm $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
-      Execute rm $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
+      #echo  rm $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
+      #Execute rm $SGE_STARTUP_FILE $RC_PREFIX/sge${RC_SUFFIX}
    elif [ "$RC_FILE" = "SGE" ]; then
       if [ $hosttype = "master" ]; then
         DARWIN_GEN_REPLACE="#GENMASTERRC"
