# New ports collection makefile for:	HDF_lib
# Version required:	4.1r2
# Date created:		17 November 1996
# Whom:			mi
#
# $FreeBSD$
#

DISTNAME=	HDF4.1r2
PKGNAME=	hdf-4.1r2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/HDF4.1r2/tar/

MAINTAINER=	mi@aldan.ziplink.net

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

MAN1=		hdf.1 hdfunpac.1 ncdump.1 ncgen.1

GNU_CONFIGURE=	yes
FC?=		f77 # Can also be g77 for the newer one
MAKE_FLAGS=	CC="$(CC)" FC="${FC}" -f
MAKE_ENV=	pwrkdir=${WRKDIR}
#"wrkdir" doesn't work for some reason in the above

# This will create dummy Makefiles and some links in the jpeg and libz
# subdirectories. This way, we do not need to hunt all the dependencies
# out. Shame on the lib's developers, though, this can not be done through
# `configure'.	-mi
pre-build:
	${AR} -r ${WRKDIR}/libz.a /dev/null
	${RANLIB} ${WRKDIR}/libz.a
	test -d ${WRKSRC}/hdf/jpeg.came-with-HDF || \
		${MV} -f ${WRKSRC}/hdf/jpeg ${WRKSRC}/hdf/jpeg.came-with-HDF
	-${MKDIR} ${WRKSRC}/hdf/jpeg
	${RM} -f ${WRKSRC}/hdf/jpeg/Makefile
	${ECHO} #Phony makefile > ${WRKSRC}/hdf/jpeg/Makefile
	${ECHO} >> ${WRKSRC}/hdf/jpeg/Makefile
	${ECHO} libjpeg.a: >> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\t@${ECHO} Using the already installed JPEG library\n' \
		>> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\nclean:\n\ttrue\n' >> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\ninstall-lib:\n\ttrue\n' >> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\ninstall:\n\ttrue\n' >> ${WRKSRC}/hdf/jpeg/Makefile
	-${LN} -s ${PREFIX}/lib/libjpeg* ${WRKSRC}/hdf/jpeg/
	-${LN} -s ${PREFIX}/include/j*.h ${WRKSRC}/hdf/jpeg/
	test -d ${WRKSRC}/hdf/zlib.came-with-HDF || \
		${MV} -f ${WRKSRC}/hdf/zlib ${WRKSRC}/hdf/zlib.came-with-HDF
	-${MKDIR} ${WRKSRC}/hdf/zlib
	${RM} -f ${WRKSRC}/hdf/zlib/Makefile
	${ECHO} #Phony makefile > ${WRKSRC}/hdf/zlib/Makefile
	${ECHO} >> ${WRKSRC}/hdf/zlib/Makefile
	${ECHO} libzlib.a: >> ${WRKSRC}/hdf/zlib/Makefile
	printf '\t@${ECHO} Using the already installed ZLIB library\n' \
		>> ${WRKSRC}/hdf/zlib/Makefile
	printf '\nclean:\n\ttrue\n' >> ${WRKSRC}/hdf/zlib/Makefile
	printf '\ninstall-lib:\n\ttrue\n' >> ${WRKSRC}/hdf/zlib/Makefile
	printf '\ninstall:\n\ttrue\n' >> ${WRKSRC}/hdf/zlib/Makefile
	-${LN} -s /usr/lib/${BINFORMAT}/libz* ${WRKSRC}/hdf/zlib/
	-${LN} -s /usr/include/zconf.h /usr/include/zlib.h ${WRKSRC}/hdf/zlib/

post-install:
	@for binary in `${GREP} ^bin/ ${PLIST}` ; do strip ${PREFIX}/$$binary; done

test:
	cd ${WRKSRC}; make ${MAKE_FLAGS} ${MAKEFILE} test

.include <bsd.port.mk>
