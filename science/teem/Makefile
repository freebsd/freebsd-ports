# $FreeBSD$

PORTNAME=	teem
DISTVERSION=	1.11.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Libraries for representing, processing and visualizing scientific data

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/Teem
	${MV} ${STAGEDIR}${PREFIX}/lib/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake/Teem

.include <bsd.port.mk>
