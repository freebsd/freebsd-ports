# $FreeBSD$

PORTNAME=	coordgenlibs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0-6
DISTVERSIONSUFFIX=	-g95e2367
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

DATADIR=	${LOCALBASE}/share/coordgen

CMAKE_ON=	COORDGEN_USE_MAEPARSER
CMAKE_OFF=	COORDGEN_BUILD_TESTS COORDGEN_BUILD_EXAMPLE

post-patch: # see https://github.com/schrodinger/coordgenlibs/issues/64
	@${REINPLACE_CMD} 's|return getTempFileProjDir() + suffix;|return "${DATADIR}/templates.mae";|' ${WRKSRC}/sketcherMinimizer.cpp

post-install: # see https://github.com/schrodinger/coordgenlibs/issues/64
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/templates.mae ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
