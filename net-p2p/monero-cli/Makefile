# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monero-cli
PORTVERSION=	0.12.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
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
		libnorm.so:net/norm \
		libpgm.so:net/openpgm \
		libunbound.so:dns/unbound \
		libunwind.so:devel/libunwind \
		libzmq.so:net/libzmq4
BUILD_DEPENDS=	${LOCALBASE}/include/zmq.hpp:net/cppzmq

USES=		cmake compiler:c++11-lib pkgconfig readline ssl
USE_GITHUB=	yes
GH_ACCOUNT=	monero-project
GH_PROJECT=	monero
CFLAGS+=	-D_WANT_SEMUN
LLD_UNSAFE=	yes

OPTIONS_DEFINE=		DOXYGEN
DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	BUILD_DOCUMENTATION

USE_RC_SUBR=	monerod

USERS=		monero
GROUPS=		monero

PLIST_FILES=	\
		bin/monero-blockchain-blackball \
		bin/monero-blockchain-export \
		bin/monero-blockchain-import \
		bin/monero-blockchain-usage \
		bin/monero-gen-trusted-multisig \
		bin/monero-wallet-cli \
		bin/monero-wallet-rpc \
		bin/monerod

.include <bsd.port.mk>
