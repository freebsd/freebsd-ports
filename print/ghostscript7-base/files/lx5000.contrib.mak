### ----------------- LexMark 5000 printer ----------------------------- ###
### Note: this driver was contributed by users.  Please contact:         ###
###   Peter B. West <p.west@uq.net.au>                                   ###

lx5000_=$(GLOBJ)gdevlx50.$(OBJ)
$(DD)lx5000.dev:    $(lx5000_)
	$(SETPDEV) $(DD)lx5000 $(lx5000_)

$(GLOBJ)gdevlx50.$(OBJ): $(GLSRC)gdevlx50.c $(PDEVH)
	$(GLCC) $(GLO_)gdevlx50.$(OBJ) $(C_) $(GLSRC)gdevlx50.c

