# ------ The Lexmark 5700 and 7000 devices ------ #

lex7000_=$(GLOBJ)gdevlx7.$(OBJ)
$(DD)lex7000.dev: $(lex7000_) $(DD)page.dev
	$(SETPDEV) $(DD)lex7000 $(lex7000_)

lex5700_=$(GLOBJ)gdevlx7.$(OBJ)
$(DD)lex5700.dev: $(lex5700_) $(DD)page.dev
	$(SETPDEV) $(DD)lex5700 $(lex5700_)

lex3200_=$(GLOBJ)gdevlx7.$(OBJ)
$(DD)lex3200.dev: $(lex3200_) $(DD)page.dev
	$(SETPDEV) $(DD)lex3200 $(lex3200_)

lex2050_=$(GLOBJ)gdevlx7.$(OBJ)
$(DD)lex2050.dev: $(lex2050_) $(DD)page.dev
	$(SETPDEV) $(DD)lex2050 $(lex2050_)

$(GLOBJ)gdevlx7.$(OBJ): $(GLSRC)gdevlx7.c $(PDEVH)
	$(GLCC) $(GLO_)gdevlx7.$(OBJ) $(C_) $(GLSRC)gdevlx7.c

