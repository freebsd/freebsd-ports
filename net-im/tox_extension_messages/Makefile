PORTNAME=	tox_extension_messages
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Message extension library for tox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopus.so:audio/opus \
		libsodium.so:security/libsodium \
		libtoxcore.so:net-im/tox \
		libtoxext.so:net-im/toxext \
		libvpx.so:multimedia/libvpx

USES=		cmake localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	toxext

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
