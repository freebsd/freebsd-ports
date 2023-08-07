PORTNAME=	nflib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-23
DISTVERSIONSUFFIX=	-g5cf40ed
PORTREVISION=	4
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NTT-based fast lattice cryptography library
WWW=		https://github.com/quarkslab/NFLlib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT_LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	unconditionally includes amd64 assembler code

BUILD_DEPENDS=	as:devel/binutils
LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp

USES=		cmake:testing compiler:c++11-lang localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	quarkslab
GH_PROJECT=	NFLlib

.if !defined(WITH_DEBUG)
CMAKE_ON=	NFL_OPTIMIZED
.endif

.include <bsd.port.mk>
