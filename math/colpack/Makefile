PORTNAME=	colpack
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.10-249
DISTVERSIONSUFFIX=	-g9a7293a
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graph Coloring Algorithm Package

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	CSCsw
GH_PROJECT=	ColPack

CMAKE_SOURCE_PATH=	${WRKSRC}/build/cmake

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.include <bsd.port.mk>
