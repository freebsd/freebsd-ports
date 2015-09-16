### --------------- Gimp-Print/stp Driver ---------------------------- ###
### Be careful to add the exact contents of this file; cut and paste   ###
### may corrupt the file and cause mysterious make errors              ###

stp_=$(GLOBJ)gdevstp.$(OBJ)

STPLIB=gimpprint

$(DD)stp.dev:	$(stp_) $(DD)page.dev
	$(SETPDEV) $(DD)stp $(stp_)
	$(ADDMOD) $(DD)stp -lib $(STPLIB)

$(GLOBJ)gdevstp.$(OBJ) : $(GLSRC)gdevstp.c $(PDEVH)
	$(GLCC) $(GLO_)gdevstp.$(OBJ) $(C_) $(GLSRC)gdevstp.c
