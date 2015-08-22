### ------- Epson ESC/Page printer device ----------------- ###
epag_=$(GLOBJ)gdevepag.$(OBJ)

$(DD)epag.dev : $(epag_) $(DD)page.dev
	$(SETPDEV) $(DD)epag $(epag_)

$(GLOBJ)gdevepag.$(OBJ): $(GLSRC)gdevepag.c $(gdevprn_h) $(PDEVH)
	$(GLCC) $(GLO_)gdevepag.$(OBJ) $(C_) $(GLSRC)gdevepag.c
