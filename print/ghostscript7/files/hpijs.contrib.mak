### ------------- IJS Interface -------------- ###

ijs_=$(GLOBJ)gdevijs.$(OBJ) $(GLOBJ)ijs_client.$(OBJ) $(GLOBJ)ijs_exec_unix.$(OBJ) $(GLOBJ)ijs.$(OBJ)

$(GLOBJ)ijs_client.$(OBJ) : $(GLSRC)ijs_client.c $(PDEVH)
	$(GLCC) $(GLO_)ijs_client.$(OBJ) $(C_) $(GLSRC)ijs_client.c

$(GLOBJ)ijs_exec_unix.$(OBJ) : $(GLSRC)ijs_exec_unix.c $(PDEVH)
	$(GLCC) $(GLO_)ijs_exec_unix.$(OBJ) $(C_) $(GLSRC)ijs_exec_unix.c

$(GLOBJ)ijs.$(OBJ) : $(GLSRC)ijs.c $(PDEVH)
	$(GLCC) $(GLO_)ijs.$(OBJ) $(C_) $(GLSRC)ijs.c

$(GLOBJ)gdevijs.$(OBJ) : $(GLSRC)gdevijs.c $(PDEVH)
	$(GLCC) $(GLO_)gdevijs.$(OBJ) $(C_) $(GLSRC)gdevijs.c

$(DD)ijs.dev : $(ijs_) $(DD)page.dev
	$(SETPDEV) $(DD)ijs $(ijs_)

