# $FreeBSD$

PORTNAME=	z3
DISTVERSIONPREFIX=	z3-
DISTVERSION=	4.8.6
CATEGORIES=	math

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Z3 Theorem Prover

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang python:2.7,build
USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		DEBUG STATIC GMP

OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ON=	--debug

STATIC_DESC=		Build static z3 library
STATIC_CONFIGURE_ON=	--staticlib

GMP_DESC=		Use GMP library for AP arithmetic
GMP_CONFIGURE_ON=	--gmp
GMP_USES=		localbase:ldflags
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

LDFLAGS_i386=		-Wl,-znotext
BUILD_WRKSRC=		${WRKSRC}/build
INSTALL_WRKSRC=		${WRKSRC}/build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/z3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libz3.so
	${LN} -s libz3.so ${STAGEDIR}${PREFIX}/lib/libz3.so.0

.include <bsd.port.mk>
