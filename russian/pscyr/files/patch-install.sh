--- install.sh.orig	Fri Jun 22 14:20:56 2001
+++ install.sh	Wed Mar 23 17:45:52 2005
@@ -3,27 +3,32 @@
 # Before running the script, choose how you'll update the pscyr.map file
 # (see below).
 
-TEXMF=`kpsewhich -expand-var='$TEXMFMAIN'`
-mkdir -p $TEXMF/{tex/latex,fonts/tfm/public,fonts/vf/public,fonts/type1/public,fonts/afm/public,doc/fonts}/pscyr
-mv dvips/base/* $TEXMF/dvips/base
-mv dvips/config/* $TEXMF/dvips/config
-mv tex/latex/pscyr/* $TEXMF/tex/latex/pscyr
-mv fonts/tfm/public/pscyr/* $TEXMF/fonts/tfm/public/pscyr
-mv fonts/vf/public/pscyr/* $TEXMF/fonts/vf/public/pscyr
-mv fonts/type1/public/pscyr/* $TEXMF/fonts/type1/public/pscyr
-mv fonts/afm/public/pscyr/* $TEXMF/fonts/afm/public/pscyr
-mv LICENSE doc/README.koi doc/PROBLEMS $TEXMF/doc/fonts/pscyr
+for idir in tex/latex fonts/tfm/public fonts/vf/public \
+	fonts/type1/public fonts/afm/public \
+	fonts/enc/dvips fonts/map/dvips fonts/map/dvipdfm doc/fonts
+  	do mkdir -p ${TEXMFDIR}/$idir/pscyr
+done
 
-VARTEXFONTS=`kpsewhich -expand-var='$VARTEXFONTS'`
-rm -f $VARTEXFONTS/pk/modeless/public/pscyr/*
+${BSD_INSTALL_DATA} dvips/base/t2a.enc ${TEXMFDIR}/fonts/enc/dvips/pscyr
+${BSD_INSTALL_DATA} dvips/config/pscyr.map ${TEXMFDIR}/fonts/map/dvips/pscyr
+${BSD_INSTALL_DATA} dvipdfm/base/pscyr2.map ${TEXMFDIR}/fonts/map/dvipdfm/pscyr
+${BSD_INSTALL_DATA} tex/latex/pscyr/* ${TEXMFDIR}/tex/latex/pscyr
+${BSD_INSTALL_DATA} fonts/tfm/public/pscyr/* ${TEXMFDIR}/fonts/tfm/public/pscyr
+${BSD_INSTALL_DATA} fonts/vf/public/pscyr/* ${TEXMFDIR}/fonts/vf/public/pscyr
+${BSD_INSTALL_DATA} fonts/type1/public/pscyr/* ${TEXMFDIR}/fonts/type1/public/pscyr
+${BSD_INSTALL_DATA} fonts/afm/public/pscyr/* ${TEXMFDIR}/fonts/afm/public/pscyr
+${BSD_INSTALL_DATA} LICENSE doc/README.koi doc/PROBLEMS ${TEXMFDIR}/doc/fonts/pscyr
+
+#VARTEXFONTS=`kpsewhich -expand-var='$VARTEXFONTS'`
+#rm -f $VARTEXFONTS/pk/modeless/public/pscyr/*
 
 # Next, we need to update psfonts.map.  The simplest (but not the best)
 # method is to uncomment the following two lines.  A better solution is
 # to add the line "pscyr.map" to the extra_module section of updmap script
 # and then run it.
 #
-#cd $TEXMF/dvips/config
+#cd ${TEXMFDIR}/dvips/config
 #cat pscyr.map >> psfonts.map
 
-mktexlsr
+#mktexlsr
 
