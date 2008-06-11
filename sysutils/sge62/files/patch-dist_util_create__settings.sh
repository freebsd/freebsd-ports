
$FreeBSD$

--- dist/util/create_settings.sh.orig
+++ dist/util/create_settings.sh
@@ -106,6 +106,7 @@
 #ENFORCE_SHLIBPATH#echo 'case "sol*":'                           >> $SP_CSH
 #ENFORCE_SHLIBPATH#echo 'case "lx*":'                            >> $SP_CSH
 #ENFORCE_SHLIBPATH#echo 'case "hp11-64":'                        >> $SP_CSH
+#ENFORCE_SHLIBPATH#echo 'case "fbsd-*":'                         >> $SP_CSH
 #ENFORCE_SHLIBPATH#echo '   breaksw'                             >> $SP_CSH
 echo 'case "*":'                                                 >> $SP_CSH
 echo "   set shlib_path_name = \`\$SGE_ROOT/util/arch -lib\`"       >> $SP_CSH
@@ -160,7 +161,7 @@
 
 echo '# library path setting required only for architectures where RUNPATH is not supported' >> $SP_SH
 echo 'case $ARCH in'                                                >> $SP_SH
-#ENFORCE_SHLIBPATH#echo 'sol*|lx*|hp11-64)'                         >> $SP_SH
+#ENFORCE_SHLIBPATH#echo 'sol*|lx*|hp11-64|fbsd-*)'                  >> $SP_SH
 #ENFORCE_SHLIBPATH#echo '   ;;'                                     >> $SP_SH
 echo '*)'                                                           >> $SP_SH
 echo "   shlib_path_name=\`\$SGE_ROOT/util/arch -lib\`"             >> $SP_SH
