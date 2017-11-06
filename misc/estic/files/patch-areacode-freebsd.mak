--- areacode/make/freebsd.mak.orig	2014-03-28 15:39:11 UTC
+++ areacode/make/freebsd.mak
@@ -0,0 +1,115 @@
+# *****************************************************************************
+# *									      *
+# *			  AREACODE Makefile for Freebsd			      *
+# *									      *
+# * (C) 1995-97  Ullrich von Bassewitz					      *
+# *		 Wacholderweg 14					      *
+# *		 D-70597 Stuttgart					      *
+# * EMail:	 uz@ibb.schwaben.com					      *
+# *									      *
+# *****************************************************************************
+
+
+
+# $Id$
+#
+# $Log$
+#
+#
+
+
+# ------------------------------------------------------------------------------
+# Stuff you may want to edit
+
+# The name of the data file after installation. You may want to define
+# AREACODE_DATAFILE before calling make instead
+.if defined(AREACODE_DATAFILE)
+DATATARGET=$(AREACODE_DATAFILE)
+.else
+DATATARGET=/usr/lib/areacodes
+.endif
+
+# Command line for the installation of the data file
+INSTALL	= install -o bin -g bin -m 644
+
+# ------------------------------------------------------------------------------
+# Definitions
+
+# Names of executables
+AS = gas
+AR = ar
+LD = ld
+ZIP = zip
+CC ?= gcc295
+
+CFLAGS	+= -DFREEBSD -g -Wall 
+
+# Name of the data file
+DATASOURCE=areacode.dat
+
+# ------------------------------------------------------------------------------
+# Implicit rules
+
+.c.o:
+	$(CC) $(CFLAGS) -c $<
+
+# ------------------------------------------------------------------------------
+#
+
+all:	actest acvers 
+
+actest:		areacode.o actest.o
+		$(CC) -o actest areacode.o actest.o
+
+acvers:		acvers.o
+		$(CC) -o acvers acvers.o
+
+areacode.o:	areacode.h areacode.c
+		$(CC) $(CFLAGS) -DDATA_FILENAME="\"$(DATATARGET)\"" \
+		-DCHARSET_ISO -c -o areacode.o areacode.c
+
+install:	areacode.o acvers
+		@if [ `id -u` != 0 ]; then				      \
+		    echo "";						      \
+		    echo 'Do "make install" as root';			      \
+		    echo "";						      \
+		    false;						      \
+		fi
+		@if [ -f $(DATATARGET) ]; then				      \
+		    NewVersion=`./acvers $(DATASOURCE) | awk '{ print $$3 }'`;\
+		    OldVersion=`./acvers $(DATATARGET) | awk '{ print $$3 }'`;\
+		    echo "Current datafile build number:  $$OldVersion";      \
+		    echo "Build number of new datafile:   $$NewVersion";      \
+		    if [ $$NewVersion -gt $$OldVersion ]; then                \
+			echo "Installing new datafile";			      \
+			$(INSTALL) $(DATASOURCE) $(DATATARGET);		      \
+		    else						      \
+			echo "Installed datafile is same or newer, skipping...";\
+		    fi;							      \
+		else							      \
+		    echo "Installing new datafile";			      \
+		    $(INSTALL) $(DATASOURCE) $(DATATARGET);		      \
+		fi
+
+# ------------------------------------------------------------------------------
+# Create a dependency file
+
+depend dep:
+	@echo "Creating dependency information"
+	$(CC) $(CFLAGS) -MM *.c > .depend
+
+# ------------------------------------------------------------------------------
+# clean up
+
+distclean:	clean
+	-rm -f *.bak *~ .depend
+
+
+clean:
+	-rm -f *.o
+	-rm -f acvers actest
+
+zap:	distclean
+
+
+
