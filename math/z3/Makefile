PORTNAME=	z3
DISTVERSIONPREFIX=	z3-
DISTVERSION=	4.12.4
CATEGORIES=	math

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Z3 Theorem Prover
WWW=		https://github.com/Z3Prover/z3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang python:build
USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		DEBUG STATIC GMP

OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ON=	--debug
DEBUG_VARS=		with_debug=yes

STATIC_DESC=		Build static z3 library
STATIC_CONFIGURE_ON=	--staticlib

GMP_DESC=		Use GMP library for AP arithmetic
GMP_CONFIGURE_ON=	--gmp
GMP_USES=		localbase:ldflags
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

CXXFLAGS_i386=	-fPIC
CXXFLAGS_armv7=	-fPIC
CXXFLAGS_powerpc=	-fPIC
LDFLAGS_i386=		-Wl,-znotext
BUILD_WRKSRC=		${WRKSRC}/build
INSTALL_WRKSRC=		${WRKSRC}/build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/z3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libz3.so
	${LN} -s libz3.so ${STAGEDIR}${PREFIX}/lib/libz3.so.0

.include <bsd.port.mk>
