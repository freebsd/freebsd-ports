# $FreeBSD$

PROG		 = ncdump
MANDIR		 = ${PREFIX}/man/man

LDFLAGS		+= -L${.CURDIR}/../libsrc -L${.CURDIR}/../../hdf/src -lmfhdf -ldf
CFLAGS		+= -I${.CURDIR}/../libsrc
SRCS		=  ncdump.c vardata.c dumplib.c

.include <bsd.prog.mk>

ENVIR		= env LD_LIBRARY_PATH=${.CURDIR}/../../hdf/src:${.CURDIR}/../libsrc
NCGEN		= ${.CURDIR}/../ncgen/ncgen

test:		$(PROG) test0.cdl
	${ENVIR} $(NCGEN) -o test0.nc -n test0.cdl
	${ENVIR} ./$(PROG) test0.nc > test1.cdl
	${ENVIR} $(NCGEN) -o test1.nc -n test1.cdl
	${ENVIR} ./$(PROG) -n test0 test1.nc > test2.cdl
	@cmp test1.cdl test2.cdl && \
	    echo "*** $(PROGRAM) test successful ***" ; \
	    rm test1.cdl test1.nc test2.cdl
