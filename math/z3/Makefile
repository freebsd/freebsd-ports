PORTNAME=	z3
DISTVERSIONPREFIX=	z3-
DISTVERSION=	4.13.0
CATEGORIES=	math

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Z3 Theorem Prover
WWW=		https://github.com/Z3Prover/z3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover

OPTIONS_DEFINE=		GMP

OPTIONS_SUB=		yes

GMP_DESC=		Use GMP library for AP arithmetic
GMP_CMAKE_BOOL=		Z3_USE_LIB_GMP
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

CMAKE_ARGS=		-DCMAKE_INSTALL_PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
