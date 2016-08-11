--- base/unixinst.mak.orig	2015-03-30 08:21:24 UTC
+++ base/unixinst.mak
@@ -45,7 +45,7 @@ ps2ascii ps2epsi ps2pdf ps2pdf12 ps2pdf1
 wftopfa fixmswrd.pl lprsetup.sh pj-gs.sh pv.sh sysvlp.sh unix-lpr.sh ;\
 	do if ( test -f $(PSLIBDIR)/$$f ); then \
 	  (cat $(PSLIBDIR)/$$f | sed -e "s/GS_EXECUTABLE=gs/GS_EXECUTABLE=$(GS)/" > $(PSOBJDIR)/$$f); \
-	  $(INSTALL_PROGRAM) $(PSOBJDIR)/$$f $(DESTDIR)$(scriptdir)/$$f; \
+	  $(INSTALL_SCRIPT) $(PSOBJDIR)/$$f $(DESTDIR)$(scriptdir)/$$f; \
 	fi;\
 	done'
 
@@ -142,7 +142,7 @@ install-doc: $(PSDOCDIR)/News.htm
 	done'
 
 # install the man pages for each locale
-MAN_LCDIRS=. de
+MAN_LCDIRS=.
 MAN1_LINKS_PS2PS=eps2eps
 MAN1_LINKS_PS2PDF=ps2pdf12 ps2pdf13 ps2pdf14
 MAN1_LINKS_GSLP=gsbj gsdj gsdj500 gslj
