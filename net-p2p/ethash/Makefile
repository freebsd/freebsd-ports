PORTNAME=	ethash
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	net-p2p

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C/C++ implementation of Ethash and ProgPoW
WWW=		https://github.com/chfast/ethash

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbenchmark.so:devel/benchmark \
		libgtest.so:devel/googletest

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	chfast

CMAKE_OFF=	HUNTER_ENABLED

.include <bsd.port.mk>
