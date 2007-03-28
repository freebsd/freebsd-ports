### -------------------- The Brother HL-1250 printer -------------------- ###
### This printer is ljet4-compatible, plus support for source tray        ###
### selection and special 1200x600 dpi mode.                              ###

hl1250_=$(GLOBJ)gdevhl12.$(OBJ) $(HPDLJM)
$(DD)hl1250.dev : $(hl1250_) $(DD)page.dev
	$(SETPDEV) $(DD)hl1250 $(hl1250_)

$(DD)hl1240.dev : $(hl1250_) $(DD)page.dev
	$(SETPDEV) $(DD)hl1240 $(hl1250_)

# Author: Marek Michalkiewicz <marekm@linux.org.pl>
# Printer: Brother HL-1250 (may work with some other models too)
$(GLOBJ)gdevhl12.$(OBJ) : $(GLSRC)gdevhl12.c $(PDEVH) $(gdevdljm_h)
	$(GLCC) $(GLO_)gdevhl12.$(OBJ) $(C_) $(GLSRC)gdevhl12.c

