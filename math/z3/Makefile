PORTNAME=	z3
DISTVERSION=	4.15.3.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Z3Prover/z3/releases/download/${PORTNAME}-${DISTVERSION:R}/
DISTNAME=	${PORTNAME}_solver-${DISTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Z3 Theorem Prover
WWW=		https://github.com/Z3Prover/z3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++20-lang localbase:ldflags

CMAKE_ARGS=	-DCMAKE_INSTALL_PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig
CMAKE_OFF=	Z3_ENABLE_EXAMPLE_TARGETS

WRKSRC_SUBDIR=	core

OPTIONS_DEFINE=	GMP
OPTIONS_SUB=	yes

GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CMAKE_BOOL=		Z3_USE_LIB_GMP

.include <bsd.port.mk>
