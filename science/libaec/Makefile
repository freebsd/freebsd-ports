PORTNAME=	libaec
PORTVERSION=	1.1.6
CATEGORIES=	science
MASTER_SITES=	https://github.com/Deutsches-Klimarechenzentrum/libaec/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library
WWW=		https://gitlab.dkrz.de/dkrz-sw/libaec \
		https://github.com/Deutsches-Klimarechenzentrum/libaec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing

CMAKE_OFF=	AEC_FUZZING \
		BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		libaec_INCLUDE_PACKAGING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
