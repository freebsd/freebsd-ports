
# build escputil command from gimp-print sources

escputil: $(GLSRC)escputil.c
	$(CC_) -o $(GLSRC)escputil $(GLSRC)escputil.c

