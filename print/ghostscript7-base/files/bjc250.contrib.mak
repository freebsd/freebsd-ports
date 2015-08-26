### ----------------- The BJC-210/240/250/250ex/265/1000 ---------------- ###

### 
### For questions about the driver, mailto://szaszg@hu.inter.net
### http://bjc250gs.sourceforge.net
###

bjc_h=$(GLSRC)gdevbjc_.h

bjc_=$(GLOBJ)gdevbjc_.$(OBJ) $(GLOBJ)gdevbjca.$(OBJ)

$(GLOBJ)gdevbjc_.$(OBJ) : $(GLSRC)gdevbjc_.c $(PDEVH) $(bjc_h)
	$(GLCC) $(GLO_)gdevbjc_.$(OBJ) $(C_) $(GLSRC)gdevbjc_.c

$(GLOBJ)gdevbjca.$(OBJ) : $(GLSRC)gdevbjca.c $(PDEVH) $(bjc_h)
	$(GLCC) $(GLO_)gdevbjca.$(OBJ) $(C_) $(GLSRC)gdevbjca.c

$(DD)bjcmono.dev : $(bjc_) $(DD)page.dev
	$(SETPDEV) $(DD)bjcmono $(bjc_)

$(DD)bjcgray.dev : $(bjc_) $(DD)page.dev
	$(SETPDEV) $(DD)bjcgray $(bjc_)

$(DD)bjccmyk.dev : $(bjc_) $(DD)page.dev
	$(SETPDEV) $(DD)bjccmyk $(bjc_)

$(DD)bjccolor.dev : $(bjc_) $(DD)page.dev
	$(SETPDEV) $(DD)bjccolor $(bjc_)

### -------------------- The H-P Color LaserJet 5/5M -------------------- ###

