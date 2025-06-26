PORTNAME=	libaec
PORTVERSION=	1.1.4
CATEGORIES=	science
MASTER_SITES=	https://github.com/MathisRosenhauer/libaec/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library
WWW=		https://gitlab.dkrz.de/k202009/libaec \
		https://github.com/MathisRosenhauer/libaec

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
