### ------------- Hewlett-Packard Co. Inkjet Driver -------------- ###

hpijs_=$(GLOBJ)gdevhpij.$(OBJ)

$(DD)gdevhpij.$(OBJ): $(GLSRC)gdevhpij.c $(PDEVH)
	$(GLCC) $(GLO_)gdevhpij.$(OBJ) $(C_) $(GLSRC)gdevhpij.c

$(DD)hpijs.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) $(DD)hpijs $(hpijs_)

$(DD)DJ630.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) DJ630 $(hpijs_)

$(DD)DJ6xx.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) DJ6xx $(hpijs_)

$(DD)DJ6xxP.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) DJ6xxP $(hpijs_)

$(DD)DJ8xx.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) DJ8xx $(hpijs_)

$(DD)DJ9xx.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) DJ9xx $(hpijs_)

$(DD)DJ9xxVIP.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) DJ9xxVIP $(hpijs_)

$(DD)AP21xx.dev : $(hpijs_) $(DD)page.dev
	$(SETPDEV) AP21xx $(hpijs_)

