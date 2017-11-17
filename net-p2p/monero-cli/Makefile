# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monero-cli
PORTVERSION=	0.11.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Private, secure, untraceable, decentralised digital currency (CLI)

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	\
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libminiupnpc.so:net/miniupnpc \
		libunwind.so:devel/libunwind \
		libzmq.so:net/libzmq4
BUILD_DEPENDS=	${LOCALBASE}/include/zmq.hpp:net/cppzmq

USES=		cmake compiler:c++11-lib pkgconfig readline ssl
USE_GITHUB=	yes
GH_ACCOUNT=	monero-project
GH_PROJECT=	monero

OPTIONS_DEFINE=		DOXYGEN
DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	BUILD_DOCUMENTATION

USE_RC_SUBR=	monerod

USERS=		monero
GROUPS=		monero

PLIST_FILES=	bin/monerod \
		bin/monero-wallet-cli \
		bin/monero-wallet-rpc

.include <bsd.port.mk>
