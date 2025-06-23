PORTNAME=	libpoly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for manipulating polynomials
WWW=		https://github.com/SRI-CSL/libpoly

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SRI-CSL

CMAKE_OFF=	LIBPOLY_BUILD_PYTHON_API LIBPOLY_BUILD_STATIC LIBPOLY_BUILD_STATIC_PIC

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

# tests as of 0.2.0: 100% tests passed, 0 tests failed out of 14

.include <bsd.port.post.mk>
