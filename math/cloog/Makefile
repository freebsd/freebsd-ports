# $FreeBSD$

PORTNAME=	cloog
PORTVERSION=	0.18.0
CATEGORIES=	math
MASTER_SITES=	http://www.bastoul.net/cloog/pages/download/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Code generator in the polyhedral model

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gmp-prefix=${PREFIX}
CONFIGURE_ENV=	pkgconfig_libdir=${PREFIX}/libdata/pkgconfig/

MAKE_JOBS_SAFE=	yes

post-install:
	${LN} -s ${PREFIX}/lib/libcloog-isl.so.4 \
		${PREFIX}/lib/libcloog-isl.so.0
	${LN} -s ${PREFIX}/lib/libisl.so.11 \
		${PREFIX}/lib/libisl.so.0

.include <bsd.port.mk>
