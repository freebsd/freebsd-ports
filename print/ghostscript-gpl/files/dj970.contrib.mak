###- cdj970 - HP 970Cxi Driver under development -------- ###
cdeskjet9_=$(GLOBJ)gdevdj9.$(OBJ) $(HPPCL)

$(DD)cdj970.dev : $(cdeskjet9_) $(DD)page.dev
	$(SETPDEV2) $(DD)cdj970 $(cdeskjet9_)

$(GLOBJ)gdevdj9.$(OBJ) : $(GLSRC)gdevdj9.c $(PDEVH) $(math__h) \
		$(gsparam_h) $(gxlum_h) $(gdevpcl_h)
	$(GLCC) $(GLO_)gdevdj9.$(OBJ) $(C_) $(GLSRC)gdevdj9.c
