### ---------------- The Samsung SmartGDI laser printer devices --------- ###
### Note : this driver is used by Samsung SmartGDI compatible printers.   ###
###

GDIMONO=$(GLOBJ)gdevgdi.$(OBJ) $(HPPCL)

$(GLOBJ)gdevgdi.$(OBJ): $(GLSRC)gdevgdi.c $(PDEVH) $(gsparam_h)
	$(GLCC) $(GLO_)gdevgdi.$(OBJ) $(C_) $(GLSRC)gdevgdi.c

$(DD)gdi.dev: $(GDIMONO) $(DD)page.dev
	$(SETPDEV) $(DD)gdi $(GDIMONO)

