--- install.sh	Mon Mar  5 23:38:33 2001
+++ install.sh	Sat Jun 30 10:23:15 2001
@@ -3,8 +3,10 @@
 # Before running the script, choose how you'll update the pscyr.map file
 # (see below).
 
-TEXMF=`kpsewhich -expand-var='$TEXMFMAIN'`
-mkdir -p $TEXMF/{tex/latex,fonts/tfm/public,fonts/vf/public,fonts/type1/public,fonts/afm/public,doc/fonts}/pscyr
+TEXMF=$1/share/texmf
+for idir in tex/latex fonts/tfm/public fonts/vf/public fonts/type1/public fonts/afm/public doc/fonts
+	do mkdir -p $TEXMF/$idir/pscyr
+done
 mv dvips/base/* $TEXMF/dvips/base
 mv dvips/config/* $TEXMF/dvips/config
 mv tex/latex/pscyr/* $TEXMF/tex/latex/pscyr
@@ -14,8 +16,8 @@
 mv fonts/afm/public/pscyr/* $TEXMF/fonts/afm/public/pscyr
 mv LICENSE doc/README.koi $TEXMF/doc/fonts/pscyr
 
-VARTEXFONTS=`kpsewhich -expand-var='$VARTEXFONTS'`
-rm -f $VARTEXFONTS/pk/modeless/public/pscyr/*
+#VARTEXFONTS=`kpsewhich -expand-var='$VARTEXFONTS'`
+#rm -f $VARTEXFONTS/pk/modeless/public/pscyr/*
 
 # Next, we need to update psfonts.map.  The simplest (but not the best)
 # method is to uncomment the following two lines.  A better solution is
@@ -25,5 +27,5 @@
 #cd $TEXMF/dvips/config
 #cat pscyr.map >> psfonts.map
 
-mktexlsr
+#mktexlsr
 
