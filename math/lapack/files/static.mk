build-static:
	cd SRC && $(AR) $(ARFLAGS) lib%%LIB%%.a $(%%LIB%%_OBJECTS)
	$(RANLIB) SRC/lib%%LIB%%.a
