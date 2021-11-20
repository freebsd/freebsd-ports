PORTNAME=		mtxclient
DISTVERSIONPREFIX=	v
DISTVERSION=		0.6.0
CATEGORIES=		net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Client API library for the Matrix protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json
LIB_DEPENDS=	\
		libcoeurl.so:ftp/coeurl \
		libolm.so:security/olm \
		libsodium.so:security/libsodium \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig ssl \
		tar:xz
CMAKE_OFF=	BUILD_LIB_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
