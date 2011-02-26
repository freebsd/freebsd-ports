# New ports collection makefile for:	cgnslib
# Date created:		Sat 24 oct 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cgnslib
DISTVERSION=	2.5-5
CATEGORIES=	science
MASTER_SITES=	SF/cgns/${PORTNAME}_${PORTVERSION:R}/Release%20${PORTVERSION:E}
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	CFD General Notation System library code

LICENSE=	AS-IS
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=all
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

.if !defined(WITHOUT_HDF5)
LIB_DEPENDS+=	hdf5.6:${PORTSDIR}/science/hdf5-18
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
PLIST_SUB=	HDF5=""
.else
CONFIGURE_ARGS+=--with-hdf5=no
PLIST_SUB=	HDF5="@comment "
.endif

.if !defined(WITHOUT_TESTS)
USE_FORTRAN=	yes
TESTSBIN=	rundbtest cgwrite cgread
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:R}
CNVBIN=		adf2hdf hdf2adf

post-build:
.if !defined(WITHOUT_TESTS)
	@(cd ${BUILD_WRKSRC}/tests;	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${BUILD_WRKSRC}/tests;	\
	${SETENV} ${MAKE_ENV} FOPTS="${FFLAGS} -I.." ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} fortran)
.endif

regression-test:
.for pg in ${TESTSBIN}
	@(cd ${BUILD_WRKSRC}/tests; ./${pg})
.endfor

post-install:
	${MV} ${PREFIX}/lib/libcgns.so ${PREFIX}/lib/libcgns.so.0
	${LN} -sf ${PREFIX}/lib/libcgns.so.0 ${PREFIX}/lib/libcgns.so
	${INSTALL_PROGRAM} ${CNVBIN:C|^|${BUILD_WRKSRC}/${OPSYS:U}/|} ${PREFIX}/bin

.include <bsd.port.mk>
