###- cdj850 - HP 850 Driver under development -------- ###
cdeskjet8_=$(GLOBJ)gdevcd8.$(OBJ) $(HPPCL)

$(DD)cdj670.dev : $(cdeskjet8_) $(DD)page.dev
	$(SETPDEV2) $(DD)cdj670 $(cdeskjet8_)

$(DD)cdj850.dev : $(cdeskjet8_) $(DD)page.dev
	$(SETPDEV2) $(DD)cdj850 $(cdeskjet8_)

$(DD)cdj880.dev : $(cdeskjet8_) $(DD)page.dev
	$(SETPDEV2) $(DD)cdj880 $(cdeskjet8_)

$(DD)cdj890.dev : $(cdeskjet8_) $(DD)page.dev
	$(SETPDEV2) $(DD)cdj890 $(cdeskjet8_)

$(DD)cdj1600.dev : $(cdeskjet8_) $(DD)page.dev
	$(SETPDEV2) $(DD)cdj1600 $(cdeskjet8_)

$(GLOBJ)gdevcd8.$(OBJ) : $(GLSRC)gdevcd8.c $(PDEVH) $(math__h)\
 $(gsparam_h) $(gxlum_h) $(gdevpcl_h)
	$(GLCC) $(GLO_)gdevcd8.$(OBJ) $(C_) $(GLSRC)gdevcd8.c
