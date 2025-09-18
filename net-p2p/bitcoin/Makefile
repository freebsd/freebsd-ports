PORTNAME=	bitcoin
PORTVERSION=	29.1
CATEGORIES=	net-p2p finance
MASTER_SITES=	https://bitcoincore.org/bin/bitcoin-core-${PORTVERSION}/ \
		LOCAL/swills:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		bitcoin128.png:icon
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${_DISTFILES:N*.png}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT?=	Virtual Peer-to-Peer Currency Client (QT)
WWW=		https://www.bitcoin.org/

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libevent.so:devel/libevent

SLAVE_PORT?=	no

USES=		cmake compiler:c++20-lang cpe pkgconfig
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils qt:5
USE_QT=		core gui network widgets buildtools:build linguisttools:build \
		qmake:build
.endif
GH_ACCOUNT=	bitcoin

CMAKE_ARGS?=	-DBUILD_GUI=ON \
		-DBUILD_CLI=OFF \
		-DBUILD_DAEMON=OFF \
		-DBUILD_SHARED_LIBS=OFF \
		-DBUILD_TX=OFF \
		-DBUILD_UTIL=OFF \
		-DBUILD_WALLET_TOOL=OFF

PLIST_FILES?=	bin/bitcoin-qt \
		share/applications/bitcoin-qt.desktop \
		share/man/man1/bitcoin-qt.1.gz \
		share/pixmaps/bitcoin128.png

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS WALLET ZMQ
OPTIONS_DEFAULT?=	DBUS HARDENING QRCODES WALLET ZMQ
OPTIONS_SUB=		yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support
ZMQ_DESC=	Block and transaction broadcasting with ZeroMQ

DBUS_USE=		QT=dbus
DBUS_CMAKE_BOOL=	WITH_DBUS

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE=Debug
DEBUG_CMAKE_OFF=	-DCMAKE_BUILD_TYPE=Release

HARDENING_CMAKE_BOOL=	ENABLE_HARDENING

QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODES_CMAKE_BOOL=	WITH_QRENCODE

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
TESTS_USE=		QT=testlib
.endif
TESTS_CMAKE_BOOL=	BUILD_BENCH BUILD_TESTS SECP256K1_BUILD_TESTS
TESTS_PLIST_FILES=	bin/bench_bitcoin \
			bin/test_bitcoin
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
TESTS_PLIST_FILES+=	bin/test_bitcoin-qt
.endif

WALLET_USES=		bdb:5 sqlite:3
WALLET_CMAKE_ON=	-DENABLE_WALLET=ON \
			-DWARN_INCOMPATIBLE_BDB=OFF \
			-DWITH_BDB=ON
WALLET_CMAKE_OFF=	-DENABLE_WALLET=OFF

ZMQ_BUILD_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_RUN_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_CMAKE_BOOL=		WITH_ZMQ

.include <bsd.port.pre.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"

post-install:
	${INSTALL} ${FILESDIR}/bitcoin-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${DISTDIR}/${DIST_SUBDIR}/bitcoin128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.endif

.include <bsd.port.post.mk>
