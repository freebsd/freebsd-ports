PORTNAME=	toxext
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extension library for tox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopus.so:audio/opus \
		libsodium.so:security/libsodium \
		libtoxcore.so:net-im/tox \
		libvpx.so:multimedia/libvpx

USES=		cmake localbase:ldflags pkgconfig
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

CFLAGS+=	-fPIC # see https://github.com/toxext/toxext/issues/7

.include <bsd.port.mk>
