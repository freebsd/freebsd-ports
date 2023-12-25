PORTNAME=	libaec
PORTVERSION=	1.1.2
CATEGORIES=	science
MASTER_SITES=	https://github.com/MathisRosenhauer/libaec/releases/download/v${PORTVERSION}/ \
		https://gitlab.dkrz.de/k202009/libaec/uploads/3847727cd2e8c941f0d68f6822a73ed7/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library
WWW=		https://gitlab.dkrz.de/k202009/libaec \
		https://github.com/MathisRosenhauer/libaec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing

CMAKE_OFF=	AEC_FUZZING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
