# Created by: Jin-Sih, Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	watchman
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06.01.00
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	File alteration monitoring service

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to build: watchman.h:169: undefined reference to '__sync_add_and_fetch_8'
BROKEN_mips64=		fails to build: watchman.h:169: undefined reference to '__sync_add_and_fetch_8'

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		liblz4.so:archivers/liblz4 \
		libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FREEBSD_ENABLE_TESTING

TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
