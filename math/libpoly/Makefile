PORTNAME=	libpoly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.13
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c1f82e63ccf3f84e2a2234589caac287d2bf6f71.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for manipulating polynomials
WWW=		https://github.com/SRI-CSL/libpoly

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SRI-CSL

CMAKE_OFF=	LIBPOLY_BUILD_PYTHON_API LIBPOLY_BUILD_STATIC LIBPOLY_BUILD_STATIC_PIC

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=unused-but-set-variable
.endif

.include <bsd.port.post.mk>
