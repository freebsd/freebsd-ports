# $FreeBSD$

.PATH:  ${.CURDIR} ${.CURDIR}/../fortran/config ${.CURDIR}/../fortran

SRCS		= array.c attr.c cdf.c dim.c file.c iarray.c error.c \
		  globdef.c putget.c putgetg.c sharray.c string.c var.c \
		  hdfsds.c mfsd.c nssdc.c xdrposix.c \
		  jackets-fbsd.c mfsdf.c mfsdff.f

LIB		= mfhdf
SHLIB_MAJOR	= 2
SHLIB_MINOR	= 3

LIBDIR		= ${PREFIX}/lib

# uncomment the line below to avoid building static libraries
#INTERNALLIB	= Yes
# comment out the line below to build the profile libs
NOPROFILE=yes

CFLAGS	+=	-DNDEBUG -DHDF -I${.CURDIR}/../../hdf/src -I${.CURDIR}
.if ${MACHINE_ARCH} == "i386"
CFLAGS	+=	-DSWAP
.endif

LDADD	+=	-L${.CURDIR}/../../hdf/src -ldf
LDFLAGS	+=	-L. -l${LIB} ${LDADD}

afterinstall:
	install -c -o root -g wheel -m 444 hdf2netcdf.h local_nc.h \
		mfhdf.h netcdf.h ${PREFIX}/include

.include <bsd.lib.mk>

test: ${SHLIB_NAME} cdftest hdftest
	env LD_LIBRARY_PATH=${.CURDIR}:${.CURDIR}/../../hdf/src ./cdftest > cdfout.new
	@diff cdfout.new testout.sav && \
		echo "*** netCDF passes formatted test ***" || \
                (echo "*** netCDF fails formatted test ***" ; \
                echo "The above differences are OK if small")
	env LD_LIBRARY_PATH=${.CURDIR}:${.CURDIR}/../../hdf/src ./hdftest > hdfout.new
	@diff hdfout.new hdfout.sav && \
		echo "*** HDF passes formatted test ***" || \
                (echo "*** HDF fails formatted test ***" ; \
                echo "The above differences are OK if small")
