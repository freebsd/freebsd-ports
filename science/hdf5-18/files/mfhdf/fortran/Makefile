# $FreeBSD$

.PATH:	${.CURDIR} ${.CURDIR}/config

all:

NOMAN	 =	1

FFLAGS	+=	${CFLAGS} -DNDEBUG -Nn802 -Nx400

LDFLAGS	+=	-L${.CURDIR}/../libsrc -L${.CURDIR}/../../hdf/src -lmfhdf -ldf

afterinstall:
	install -c -o root -g wheel -m 444 config/netcdf-fbsd.inc \
		${PREFIX}/include/netcdf.inc

.include <bsd.prog.mk>

ENVIR	 =	env LD_LIBRARY_PATH=${.CURDIR}/../libsrc:${.CURDIR}/../../hdf/src

CLEANFILES+=	hdftest hdftest.o ftest ftest-fbsd.o

config/netcdf.inc:
	ln -s netcdf-fbsd.inc config/netcdf.inc

ftest:	ftest-fbsd.f config/netcdf.inc
	${MAKE} PROG=$@ SRCS=ftest-fbsd.f $@

hdftest: hdftest.f
	${MAKE} PROG=$@ SRCS=hdftest.f $@

test: ftest hdftest
	mkdir -p testdir
	# ================================
	#  netCDF Fortran interface tests
	# ================================
	${ENVIR} ./ftest
	${ENVIR} ./hdftest > hdfout.new
	@diff -Bb hdfout.new hdftst.sav && \
		echo "*** HDF-SD Fortran interface tests passed ***" || \
		(echo "*** HDF-SD Fortran interface tests failed ***"; \
		echo "The above differences are OK if small")
