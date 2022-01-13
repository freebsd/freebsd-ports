PORTNAME=	ethash
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	nc@FreeBSD.org
COMMENT=	C/C++ implementation of Ethash and ProgPoW

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbenchmark.so:devel/benchmark \
		libgtest.so:devel/googletest

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	chfast

CMAKE_OFF=	HUNTER_ENABLED

.include <bsd.port.mk>

