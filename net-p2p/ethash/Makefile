PORTNAME=	ethash
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-p2p

MAINTAINER=	ports@FreeBSD.org
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
