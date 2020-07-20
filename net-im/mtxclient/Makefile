# $FreeBSD$

PORTNAME=		mtxclient
DISTVERSIONPREFIX=	v
DISTVERSION=		0.3.1
PORTREVISION=	1
CATEGORIES=		net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Client API library for the Matrix protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json \
		googletest>0:devel/googletest
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

USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn

.include <bsd.port.mk>
