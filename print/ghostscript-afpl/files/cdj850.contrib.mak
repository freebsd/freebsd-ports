
###- cdj850 - HP 850 Driver under development -------- ###

cdj8_=$(GLOBJ)gdevcd8.$(OBJ) $(HPPCL)

$(DD)cdj850.dev : $(cdj8_) $(DD)page.dev
	$(SETPDEV) $(DD)cdj850 $(cdj8_)

$(GLOBJ)gdevcd8.$(OBJ) : $(GLSRC)gdevcd8.c $(std_h) $(PDEVH)\
 $(gsparam_h) $(gsstate_h) $(gxlum_h)\
 $(gdevbjc_h) $(gdevpcl_h)
	$(GLCC) $(GLO_)gdevcd8.$(OBJ) $(C_) $(GLSRC)gdevcd8.c

