# $FreeBSD$

PORTNAME=	coordgenlibs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	4
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

.include <bsd.port.mk>
