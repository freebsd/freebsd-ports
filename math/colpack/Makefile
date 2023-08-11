PORTNAME=	colpack
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.10-249
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g9a7293a
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graph Coloring Algorithm Package
WWW=		https://github.com/CSCsw/ColPack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:gcc-c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	CSCsw
GH_PROJECT=	ColPack

CMAKE_SOURCE_PATH=	${WRKSRC}/build/cmake

.include <bsd.port.mk>
