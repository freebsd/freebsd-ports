# This code was written and is copyrighted 1996,1998 by
#
#       Elmar Bartel
#       Institut fuer Informatik
#       Technische Universitaet Muenchen
#       bartel@informatik.tu-muenchen.de
#
# Permission to use, copy, modify and distribute this software
# and its documentation for any purpose, except making money, is
# herby granted, provided that the above copyright notice and
# this permission appears in all places, where this code is
# referenced or used literally.

# uncomment the settings for your system and type make.
# if there is no setting available, simply try to use
# the most closest settings. 
# Finally let me know what you used, to get it running.


## For System V4.1 (AT&T) either cc or gcc
## And for SINIX V4.1 (either mips or intel).
#ARCH=
#LIB=	-lsocket -lnsl
#CC=	cc
#OPT=	-O
#DBG=	-g
#INC=	

## For DEC (Mips)ULTRIX 4.1
#ARCH=	-Dultrix
#LIB=
#CC=	gcc
#OPT=	-O2
#DBG=	
#INC=	

## For HPUX 9.* with gcc
#ARCH=	-Dhpux9
#LIB=
#CC=	gcc
#OPT=	-O2
#DBG=	-g
#INC=	

## For HPUX 9.* with cc
#ARCH=	-Ae -Dhpux9
#LIB=
#CC=	cc
#OPT=	-O
#DBG=	-g
#INC=	


## For HPUX 10.* with gcc
#ARCH=	-Dhpux
#LIB=
#CC=	gcc
#OPT=	-O2
#DBG=	-g
#INC=	

## For HPUX 10.* with cc
#ARCH=	-Ae -Dhpux
#LIB=
#CC=	cc
#OPT=	-O
#DBG=	-g
#INC=	

## For SunOS 4.1 with clcc
#ARCH=-DSunOS4
#LIB=	
#OPT=	-O2
#CC=	clcc
#DBG=	
#INC=	

## For SunOS 4.1 with gcc
#ARCH=-DSunOS4
#LIB=	
#OPT=	-O2
#CC=	gcc
#DBG=	
#INC=	

## For SunOS 5.3 with gcc
#ARCH=-DSunOS53
#LIB=	-lsocket -lnsl -lucb
#OPT=	-O2
#CC=	gcc
#DBG=	
#INC=	

## For SunOS 5.[456] with cc from SunSoft
#ARCH=-DSunOS54
#LIB=	-lsocket -lnsl
#OPT=	-O
#CC=	/usr/ccs/bin/cc
#CC=	/opt/SUNWspro/bin/cc
#DBG=	-g
#INC=	

## For SunOS 5.[456] with gcc
#ARCH=-DSunOS54
#LIB=	-lsocket -lnsl
#OPT=	-O2
#CC=	gcc
#DBG=	-Wall -g
#INC=	

## For FreeBSD
ARCH=	-DFreeBSD
LIB=
OPT=	-O2
CC=	cc
DBG=	
INC=	

## For SGI IRIX 5.3, 6.2 (cc or gcc)
#ARCH=
#LIB=
#OPT=	-O
#CC=	cc
#DBG=	
#INC=	

## For IBM AIX 2.3
#ARCH=	-Daix
#LIB=
#OPT=	-O
#CC=	cc
#DBG=	
#INC=	

## For OSF/1 10.41
#ARCH=	
#LIB=
#OPT=	-O -Olimit 700
#CC=	cc
#DBG=	
#INC=	

## For Linux with gcc
#ARCH=
#LIB=	
#OPT=	-O2
#CC=	gcc
#DBG=	
#INC=	

VERSION=	1.4
prefix=		/usr/local/dist/DIR/nttcp-$(VERSION)
#prefix=		/usr/local
#CFLAGS =	$(ARCH) $(DBG) $(DEF) $(INC) $(OPT) -DVERSION=\"$(VERSION)\"
CFLAGS =	$(ARCH) $(CFLG) -DVERSION=\"$(VERSION)\"
LFLAGS = 	$(DBG) 

nttcp:		nttcp.o support.o
		$(CC) $(LFLAGS) nttcp.o -o nttcp support.o $(LIB)

support.o:	support.c support.h

dist:
		if [ -d nttcp-$(VERSION) ]; then \
		    rm -f nttcp-$(VERSION)/*; \
		else \
		    mkdir nttcp-$(VERSION); \
		fi
		ln nttcp.c nttcp.1 support.c support.h \
		   README Makefile nttcp-$(VERSION)
		tar cvf - nttcp-$(VERSION) | gzip > /tmp/nttcp-$(VERSION).tar.gz; \
		zip -lgr /tmp/nttcp`echo $(VERSION)|tr -d .`.zip nttcp-$(VERSION)

install:	nttcp
		-mkdir -p $(prefix)/bin
		-mkdir -p $(prefix)/man/man1
		cp nttcp $(prefix)/bin
		cp nttcp.1 $(prefix)/man/man1

clean:
		rm -f *.o

clobber:	clean
		rm -rf core nttcp nttcp-$(VERSION)
