# Created by: gahr
# $FreeBSD$

PORTNAME=	mpir
DISTVERSION=	2.7.0-alpha9
CATEGORIES=	math
MASTER_SITES=	http://www.mpir.org/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Multiprecision integer library

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-cxx
INSTALL_TARGET+=install-strip

MPIR_VERSION=	10.6.0
MPIRXX_VERSION=	4.4.0

PLIST_FILES=	include/mpir.h \
		include/mpirxx.h \
		lib/libmpir.a \
		lib/libmpir.so \
		lib/libmpir.so.${MPIR_VERSION} \
		lib/libmpir.so.${MPIR_VERSION:R:R} \
		lib/libmpirxx.a \
		lib/libmpirxx.so \
		lib/libmpirxx.so.${MPIRXX_VERSION} \
		lib/libmpirxx.so.${MPIRXX_VERSION:R:R}

post-install:
	${LN} -sf libmpir.so.${MPIR_VERSION} \
	    ${STAGEDIR}${PREFIX}/lib/libmpir.so.${MPIR_VERSION:R:R}
	${LN} -sf libmpirxx.so.${MPIRXX_VERSION} \
	    ${STAGEDIR}${PREFIX}/lib/libmpirxx.so.${MPIRXX_VERSION:R:R}

regression-test:
	${MAKE} -C ${WRKSRC} check

.include <bsd.port.mk>
