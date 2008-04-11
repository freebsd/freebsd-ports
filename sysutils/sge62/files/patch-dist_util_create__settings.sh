
$FreeBSD$

--- dist/util/create_settings.sh.orig
+++ dist/util/create_settings.sh
@@ -102,6 +102,7 @@
 echo 'switch ($ARCH)'                                            >> $SP_CSH
 #ENFORCE_SHLIBPATH#echo 'case "sol*":'                           >> $SP_CSH
 #ENFORCE_SHLIBPATH#echo 'case "lx*":'                            >> $SP_CSH
+#ENFORCE_SHLIBPATH#echo 'case "fbsd-*":'                         >> $SP_CSH
 #ENFORCE_SHLIBPATH#echo '   breaksw'                             >> $SP_CSH
 echo 'case "*":'                                                 >> $SP_CSH
 echo "   set shlib_path_name = \`\$SGE_ROOT/util/arch -lib\`"       >> $SP_CSH
@@ -154,7 +155,7 @@
 
 echo '# library path setting required only for architectures where RUNPATH is not supported' >> $SP_SH
 echo 'case $ARCH in'                                                >> $SP_SH
-#ENFORCE_SHLIBPATH#echo 'sol*|lx*)'                                 >> $SP_SH
+#ENFORCE_SHLIBPATH#echo 'sol*|lx*|fbsd-*)'                          >> $SP_SH
 #ENFORCE_SHLIBPATH#echo '   ;;'                                     >> $SP_SH
 echo '*)'                                                           >> $SP_SH
 echo "   shlib_path_name=\`\$SGE_ROOT/util/arch -lib\`"             >> $SP_SH
