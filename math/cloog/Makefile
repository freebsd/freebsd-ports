# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloog
PORTVERSION=	0.18.1
CATEGORIES=	math
MASTER_SITES=	http://www.bastoul.net/cloog/pages/download/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Code generator in the polyhedral model

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gmp-prefix=${PREFIX}
CONFIGURE_ENV=	pkgconfig_libdir=${PREFIX}/libdata/pkgconfig/

post-install:
	${LN} -s libcloog-isl.so.4 ${STAGEDIR}${PREFIX}/lib/libcloog-isl.so.0
	${LN} -s libisl.so.12 ${STAGEDIR}${PREFIX}/lib/libisl.so.0

.include <bsd.port.mk>
