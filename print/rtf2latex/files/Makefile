SHELL=/bin/sh
INSTALL_PROGRAM=${BSD_INSTALL_PROGRAM}
INSTALL_MAN=${BSD_INSTALL_MAN}
INSTALL_DATA=${BSD_INSTALL_DATA}
LD=cc -s
PREFIX?=/usr/local
# if your compiler needs -o option for creating .o files uncomment this line:
#OOPT = -o $@
#
# XCFLAGS holds a combination of -DNO_MALLOC_H -DSTDARG -DVARARGS -DSYSV.
# -DSTDARG and -DVARARGS are mutually exclusive. -DNO_MALLOC_H is only
# needed if you don't have a standard C compiler AND you don't have malloc.h
# if you have a standard C compiler, it is automatically asumed you have stdarg
# you can override this by specifying -DVARARGS. If you don't specify
# any of -DSTDARG and -DVARARGS, an uggly replacement that works on most
# K&R compilers will be used.
# -DSYSV is currently used only for defining index to strchr. You may
# want to specify this for ULTRIX - ULTRIX has both, strchr and index but
# lacks prototypes for the latter.
# 
# uncomment this line and delete unneccesary flags if needed.
#XCFLAGS=-DNO_MALLOC_H -DSTDARG -DVARARGS -DSYSV
#XCFLAGS = -DSYSV

# This is where executables, man-pages and support files are installed
BINDIR = ${PREFIX}/bin
MANDIR = ${PREFIX}/man/man1
RTFDIR = ${PREFIX}/share/rtf

############### No configuration parameters below this line ###############

# RTF-to-LaTeX translator
COMMONOBJS = reader.o
LATEXOBJS = rtf2LaTeX.o $(COMMONOBJS)
SOURCES = rtf.h Makefile.2LaTeX fonts.h rtf2LaTeX.c r2L_version.h \
	rtf2LaTeX.h reader.c
SUPPORT = mac.code ansi.code english.land german.land
DOCFILS = Copyright interna.tex README.2LaTeX interna.rtf rtf2LaTeX.man \
	INSTALL.2LaTeX
MACFILES = getopt.c macintosh.h macintosh.c readme.mac

all:	rtf2LaTeX

rtf2LaTeX: $(LATEXOBJS)
	$(LD) $(LDFLAGS) -o $@ $(LATEXOBJS)
install: rtf2LaTeX $(DOCFILS) $(SUPPORT)
	$(INSTALL_PROGRAM) rtf2LaTeX $(BINDIR)
	$(INSTALL_MAN) rtf2LaTeX.man $(MANDIR)/rtf2LaTeX.1
	-mkdir $(RTFDIR)
	$(INSTALL_DATA) ansi.code mac.code german.land english.land $(RTFDIR)
tags:
	etags -et *.[ch]
clean::
	-rm -f rtf2LaTeX *~ core *.o *.aux *.log *.dvi TAGS \
	rtf2LaTeX.tar.z rtf2LaTeX.tar.gz
test:
	./rtf2LaTeX interna.rtf > interna.test
	diff interna.test interna.tex
	rm interna.test
#
reader.o : rtf.h 
	$(CC) $(CFLAGS) $(XCFLAGS) -c $(OOPT) reader.c

rtf2LaTeX.o : fonts.h r2L_version.h rtf2LaTeX.h rtf.h
	$(CC) $(CFLAGS) $(XCFLAGS) -c -DRTFDIR=\"$(RTFDIR)\" $(OOPT) rtf2LaTeX.c

sources: $(SOURCES) $(DOCFILS) $(SUPPORT) $(MACFILES)

$(SOURCES) $(DOCFILS) $(SUPPORT) $(MACFILES):
	co $@

dist: sources
	mkdir rtf2LaTeX
	ln $(SOURCES) $(DOCFILS) $(SUPPORT) $(MACFILES) rtf2LaTeX
	tar cf - rtf2LaTeX | gzip -best > rtf2LaTeX.tar.gz
	rm -rf rtf2LaTeX
