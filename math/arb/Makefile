PORTNAME=	arb
DISTVERSION=	2.23.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for arbitrary-precision interval arithmetic
WWW=		https://arblib.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fredrik-johansson

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM:STRING=3.5 # CMake 4 compatibility

.include <bsd.port.mk>
