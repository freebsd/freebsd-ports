PORTNAME=		mtxclient
DISTVERSIONPREFIX=	v
DISTVERSION=		0.5.1
CATEGORIES=		net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Client API library for the Matrix protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_11=	unsupported SSL in base

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json
LIB_DEPENDS=	libsodium.so:security/libsodium \
		libboost_date_time.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libolm.so:security/olm \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig ssl \
		tar:xz
CMAKE_OFF=	BUILD_LIB_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
