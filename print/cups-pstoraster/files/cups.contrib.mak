### ----------------- CUPS Ghostscript Driver ---------------------- ###

cups_=  $(GLOBJ)gdevcups.$(OBJ)

$(DD)cups.dev:  $(cups_) $(DD)page.dev
	$(SETPDEV2) $(DD)cups $(cups_)
	$(ADDMOD) $(DD)cups -lib cupsimage -lib cups

$(GLOBJ)gdevcups.$(OBJ): $(GLSRC)gdevcups.c $(PDEVH)
	$(GLCC) $(GLO_)gdevcups.$(OBJ) $(C_) $(GLSRC)gdevcups.c

