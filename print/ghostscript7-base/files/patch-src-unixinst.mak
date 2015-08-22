--- src/unixinst.mak.orig	2003-01-17 09:49:05.000000000 +0900
+++ src/unixinst.mak	2015-08-22 00:31:09.540215000 +0900
@@ -30,24 +30,24 @@
 # rules, just in case bindir or scriptdir is a subdirectory of any of these.
 
 install-exec: $(GS_XE)
-	-mkdir -p $(datadir)
-	-mkdir -p $(gsdir)
-	-mkdir -p $(gsdatadir)
-	-mkdir -p $(bindir)
-	$(INSTALL_PROGRAM) $(GS_XE) $(bindir)/$(GS)
+	-mkdir -p $(DESTDIR)$(datadir)
+	-mkdir -p $(DESTDIR)$(gsdir)
+	-mkdir -p $(DESTDIR)$(gsdatadir)
+	-mkdir -p $(DESTDIR)$(bindir)
+	$(INSTALL_PROGRAM) $(GS_XE) $(DESTDIR)$(bindir)/$(GS)
 
 install-scripts: $(PSLIBDIR)/gsnd
-	-mkdir -p $(datadir)
-	-mkdir -p $(gsdir)
-	-mkdir -p $(gsdatadir)
-	-mkdir -p $(scriptdir)
+	-mkdir -p $(DESTDIR)$(datadir)
+	-mkdir -p $(DESTDIR)$(gsdir)
+	-mkdir -p $(DESTDIR)$(gsdatadir)
+	-mkdir -p $(DESTDIR)$(scriptdir)
 	$(SH) -c 'for f in \
 gsbj gsdj gsdj500 gslj gslp gsnd \
 bdftops dvipdf eps2eps font2c \
 pdf2dsc pdf2ps pdfopt pf2afm pfbtopfa printafm \
 ps2ascii ps2epsi ps2pdf ps2pdf12 ps2pdf13 ps2pdf14 ps2pdfwr ps2ps wftopfa \
 fixmswrd.pl lprsetup.sh pj-gs.sh pv.sh sysvlp.sh unix-lpr.sh ;\
-	do if ( test -f $(PSLIBDIR)/$$f ); then $(INSTALL_PROGRAM) $(PSLIBDIR)/$$f $(scriptdir); fi;\
+	do if ( test -f $(PSLIBDIR)/$$f ); then $(INSTALL_SCRIPT) $(PSLIBDIR)/$$f $(DESTDIR)$(scriptdir); fi;\
 	done'
 
 PSDOCDIR=$(PSLIBDIR)/../doc
@@ -60,10 +60,10 @@
 # one file from each subdirectory just as a sanity check.
 
 install-libdata: 
-	-mkdir -p $(datadir)
-	-mkdir -p $(gsdir)
-	-mkdir -p $(gsdatadir)
-	-mkdir -p $(gsdatadir)/lib
+	-mkdir -p $(DESTDIR)$(datadir)
+	-mkdir -p $(DESTDIR)$(gsdir)
+	-mkdir -p $(DESTDIR)$(gsdatadir)
+	-mkdir -p $(DESTDIR)$(gsdatadir)/lib
 	$(SH) -c 'for f in \
 Fontmap Fontmap.GS \
 CIDFnmap CIDFnmap.Ore CIDFnmap.ARP CIDFnmap.Bae CIDFnmap.Koc \
@@ -83,13 +83,13 @@
 viewpcx.ps viewpbm.ps viewps2a.ps \
 winmaps.ps wftopfa.ps wrfont.ps zeroline.ps \
 pdf2dsc.ps pdfopt.ps ;\
-	do if ( test -f $(PSLIBDIR)/$$f ); then $(INSTALL_DATA) $(PSLIBDIR)/$$f $(gsdatadir)/lib; fi;\
+	do if ( test -f $(PSLIBDIR)/$$f ); then $(INSTALL_DATA) $(PSLIBDIR)/$$f $(DESTDIR)$(gsdatadir)/lib; fi;\
 	done'
 	$(SH) -c 'for f in $(PSLIBDIR)/gs_*.ps $(PSLIBDIR)/pdf*.ps;\
-	do $(INSTALL_DATA) $$f $(gsdatadir)/lib ;\
+	do $(INSTALL_DATA) $$f $(DESTDIR)$(gsdatadir)/lib ;\
 	done'
 	$(SH) -c 'for f in $(PSLIBDIR)/*.ppd $(PSLIBDIR)/*.rpd $(PSLIBDIR)/*.upp $(PSLIBDIR)/*.xbm $(PSLIBDIR)/*.xpm;\
-	do $(INSTALL_DATA) $$f $(gsdatadir)/lib ;\
+	do $(INSTALL_DATA) $$f $(DESTDIR)$(gsdatadir)/lib ;\
 	done'
 
 # install html documentation
@@ -106,20 +106,20 @@
 	   Psfiles.htm Public.htm Readme.htm Release.htm \
 	   Source.htm Tester.htm Unix-lpr.htm Use.htm Xfonts.htm
 install-doc: $(PSDOCDIR)/News.htm
-	-mkdir -p $(docdir)
+	-mkdir -p $(DESTDIR)$(docdir)
 	$(SH) -c 'for f in $(DOC_PAGES) ;\
-	do if ( test -f $(PSDOCDIR)/$$f ); then $(INSTALL_DATA) $(PSDOCDIR)/$$f $(docdir); fi;\
+	do if ( test -f $(PSDOCDIR)/$$f ); then $(INSTALL_DATA) $(PSDOCDIR)/$$f $(DESTDIR)$(docdir); fi;\
 	done'
 
 # install the man pages for each locale
-MAN_LCDIRS=. de
+MAN_LCDIRS=.
 MAN1_LINKS_PS2PS=eps2eps
 MAN1_LINKS_PS2PDF=ps2pdf12 ps2pdf13
 MAN1_LINKS_GSLP=gsbj gsdj gsdj500 gslj
 install-man: $(PSMANDIR)/gs.1
-	$(SH) -c 'test -d $(mandir) || mkdir -p $(mandir)'
+	$(SH) -c 'test -d $(DESTDIR)$(mandir) || mkdir -p $(DESTDIR)$(mandir)'
 	$(SH) -c 'for d in $(MAN_LCDIRS) ;\
-	do man1dir=$(mandir)/$$d/man$(man1ext) ;\
+	do man1dir=$(DESTDIR)$(mandir)/$$d/man$(man1ext) ;\
 	  ( test -d $$man1dir || mkdir -p $$man1dir ) ;\
 	  for f in $(PSMANDIR)/$$d/*.1 ;\
 	    do $(INSTALL_DATA) $$f $$man1dir ;\
@@ -146,17 +146,22 @@
 
 # install the example files
 install-examples:
-	-mkdir -p $(exdir)
+	-mkdir -p $(DESTDIR)$(exdir)
 	for f in \
 alphabet.ps colorcir.ps doretree.ps escher.ps golfer.ps \
 grayalph.ps snowflak.ps tiger.ps vasarely.ps waterfal.ps \
 ridt91.eps ;\
-	do $(INSTALL_DATA) $(PSEXDIR)/$$f $(exdir) ;\
+	do $(INSTALL_DATA) $(PSEXDIR)/$$f $(DESTDIR)$(exdir) ;\
 	done
-	-mkdir -p $(exdir)/cjk
+	-mkdir -p $(DESTDIR)$(exdir)/cjk
 	for f in \
 all_ac1.ps all_ag1.ps all_aj1.ps all_aj2.ps all_ak1.ps \
 gscjk_ac.ps gscjk_ag.ps gscjk_aj.ps gscjk_ak.ps \
 iso2022.ps;\
-	do $(INSTALL_DATA) $(PSEXDIR)/cjk/$$f $(exdir)/cjk ;\
+	do $(INSTALL_DATA) $(PSEXDIR)/cjk/$$f $(DESTDIR)$(exdir)/cjk ;\
 	done
+
+install-shared: $(GS_SHARED_OBJS)
+	-mkdir -p $(DESTDIR)$(gssharedir)
+	$(SH) -c 'for obj in $(GS_SHARED_OBJS); do \
+	    $(INSTALL_PROGRAM) $$obj $(DESTDIR)$(gssharedir)/; done'
