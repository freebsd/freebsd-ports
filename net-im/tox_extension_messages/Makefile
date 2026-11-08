PORTNAME=	tox_extension_messages
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.3
PORTREVISION=	10
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Message extension library for tox
WWW=		https://github.com/toxext/tox_extension_messages

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
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/toxext/tox_extension_messages/issues/8

.include <bsd.port.mk>
