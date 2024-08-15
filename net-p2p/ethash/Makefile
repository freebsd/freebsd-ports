PORTNAME=	ethash
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	4
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

CFLAGS+=	-Wno-error=deprecated-declarations

.include <bsd.port.mk>
