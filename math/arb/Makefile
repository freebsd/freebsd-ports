# $FreeBSD$

PORTNAME=	arb
DISTVERSION=	2.13.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for arbitrary-precision interval arithmetic

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	fredrik-johansson
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libarb.so.*

.include <bsd.port.mk>
