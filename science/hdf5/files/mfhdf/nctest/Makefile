# $FreeBSD$

PROG		 = nctest
NOMAN		 = 1
CFLAGS		+= -I${.CURDIR}/../libsrc
LDFLAGS		+= -L${.CURDIR}/../libsrc -L${.CURDIR}/../../hdf/src -lmfhdf -ldf
SRCS		= varget.c vargetg.c varput.c varputg.c vardef.c vartests.c \
		  vputget.c vputgetg.c driver.c cdftests.c dimtests.c rec.c \
		  atttests.c misctest.c add.c error.c emalloc.c val.c slabs.c

install:

.include <bsd.prog.mk>

test:		$(PROG)
	@ echo "==========================="
	@ echo "netCDF C interface tests"
	@ echo "==========================="
	env LD_LIBRARY_PATH=${.CURDIR}/../libsrc:${.CURDIR}/../../hdf/src ./$(PROG)
