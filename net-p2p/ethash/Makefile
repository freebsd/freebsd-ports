PORTNAME=	ethash
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
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

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=strict-prototypes
.endif

.include <bsd.port.post.mk>
