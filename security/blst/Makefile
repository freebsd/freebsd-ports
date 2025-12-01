PORTNAME=	blst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.14
PORTREVISION=	2
CATEGORIES=	security devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Implementation of BLS12-381 signature algorithm
WWW=		https://github.com/supranational/blst

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	supranational

USE_LDCONFIG=	yes

SUB_FILES=	libblst.pc
SUB_LIST=	PORTVERSION=${PORTVERSION}

do-build:
	cd ${WRKSRC} && ./build.sh -shared

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libblst
	${INSTALL_DATA} ${WRKSRC}/bindings/blst_aux.h \
		${WRKSRC}/bindings/blst.h \
		${WRKSRC}/bindings/blst.hpp \
		${STAGEDIR}${PREFIX}/include/libblst
	${INSTALL_DATA} ${WRKDIR}/libblst.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_LIB} ${WRKSRC}/libblst.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
