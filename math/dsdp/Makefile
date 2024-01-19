PORTNAME=	dsdp
DISTVERSION=	5.8
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	https://www.mcs.anl.gov/hs/software/${PORTNAME:tu}/
DISTNAME=	${PORTNAME:tu}${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of interior-point method for semidefinite programming
WWW=		https://www.mcs.anl.gov/hs/software/DSDP/

LICENSE=	DSDP_LICENSE
LICENSE_NAME=	DSDP License
LICENSE_FILE=	${WRKSRC}/dsdp-license
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell # do anything as long as the original copyright notice is retained

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake localbase:ldflags
USE_LDCONFIG=	yes

ALL_TARGET=	all oshared all oshared

BINARY_ALIAS=	make=${GMAKE} gcc=${CC}
MAKE_ENV=	DSDPROOT=${WRKSRC} SH_LD="${CC} -shared -Wl,-soname,libdsdp.so.0"
CFLAGS+=	-fPIC

PLIST_FILES=	bin/dsdp5 \
		include/dsdp/dsdp5.h \
		include/dsdp/dsdpbasictypes.h \
		include/dsdp/dsdplapack.h \
		include/dsdp/dsdpmem.h \
		include/dsdp/dsdpsys.h \
		lib/libdsdp.a \
		lib/libdsdp.so.0 \
		lib/libdsdp.so

do-build: # the build fails to build all binaries without being called twice due to makefile convolution
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/dsdp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dsdp5 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libdsdp.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libdsdp.so ${STAGEDIR}${PREFIX}/lib/libdsdp.so.0
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libdsdp.so.0 libdsdp.so)
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/dsdp

.include <bsd.port.mk>
