PORTNAME=	tlfloat
DISTVERSIONPREFIX=v
DISTVERSION=	1.15.0
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ template library for floating point operations
WWW=		https://shibatch.github.io/tlfloat-doxygen/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libmpfr.so:math/mpfr

USES=		cmake:testing compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

.include <bsd.port.mk>
