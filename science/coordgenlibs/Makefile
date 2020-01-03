# $FreeBSD$

PORTNAME=	coordgenlibs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schrodinger-developed 2D coordinate generation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/dynamic_bitset.hpp:devel/boost-libs
LIB_DEPENDS=	libmaeparser.so:science/maeparser

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	schrodinger
USE_LDCONFIG=	yes

CMAKE_ARGS=	-Dmaeparser_DIR=${LOCALBASE}/lib/cmake

.include <bsd.port.mk>
