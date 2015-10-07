### ---------------- Lexmark 3200 device ----------------- ###

lxm3200_=$(GLOBJ)gdevlx32.$(OBJ)

$(DD)lxm3200.dev: $(lxm3200_) $(DD)page.dev
	$(SETPDEV) $(DD)lxm3200 $(lxm3200_)

$(GLOBJ)gdevlx32.$(OBJ): $(GLSRC)gdevlx32.c $(PDEVH) $(gsparam_h)
	$(GLCC) $(GLO_)gdevlx32.$(OBJ) $(C_) $(GLSRC)gdevlx32.c

