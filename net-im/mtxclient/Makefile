# $FreeBSD$

PORTNAME=		mtxclient
DISTVERSIONPREFIX=	v
DISTVERSION=		0.2.1
PORTREVISION=	7
CATEGORIES=		net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Client API library for the Matrix protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json \
		spdlog>=1.3:devel/spdlog \
		googletest>0:devel/googletest
LIB_DEPENDS=	libsodium.so:security/libsodium \
		libboost_date_time.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libolm.so:security/olm

USES=		cmake compiler:c++11-lang pkgconfig \
		localbase:ldflags tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn

# 71 files use #include <json.hpp>, which needs to be
# elsewhere; an alternative would be to bung in -I${LOCALBASE}/include/nlohmann
post-patch:
	${FIND} ${WRKSRC} -type f -print0 | \
	${XARGS} -0 ${REINPLACE_CMD} \
		's+include <json.hpp>+include <nlohmann/json.hpp>+'

.include <bsd.port.mk>
