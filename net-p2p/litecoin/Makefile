# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	litecoin
PORTVERSION=	0.14.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-p2p finance

MAINTAINER=	swills@FreeBSD.org
COMMENT?=	Virtual Peer-to-Peer Currency Client (QT)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to configure: "Big Endian not supported"

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libevent.so:devel/libevent

USES+=		autoreconf compiler:c++11-lib gmake libtool pkgconfig shebangfix ssl
SHEBANG_FILES=	src/test/*.py
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

SLAVE_PORT?=	no

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils
USE_QT5=	core gui network widgets \
		buildtools_build linguisttools_build qmake_build

BUILD_DEPENDS+=	protoc:devel/protobuf
LIB_DEPENDS+=	libprotobuf.so:devel/protobuf

TESTS_USE=		QT5=testlib
TESTS_PLIST_FILES=	bin/test_litecoin-qt \
			bin/test_litecoin
.endif

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT?=	DBUS HARDENING QRCODES UPNP WALLET
OPTIONS_SUB=		yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support
ZMQ_DESC=	Block and transaction broadcasting with ZeroMQ

DBUS_CONFIGURE_WITH=	dbus
DBUS_USE=		QT5=dbus

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

HARDENING_CONFIGURE_ENABLE=	hardening

TESTS_CONFIGURE_ENABLE=	tests bench
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "yes"
TESTS_PLIST_FILES=	bin/test_litecoin
.endif
TESTS_PLIST_FILES+=	bin/bench_litecoin

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=		-L${LOCALBASE}/lib

QRCODES_CONFIGURE_WITH=	qrencode
QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

WALLET_CONFIGURE_ENABLE=	wallet
WALLET_CXXFLAGS=		-I${BDB_INCLUDE_DIR}
WALLET_LIBS=			-L${BDB_LIB_DIR}
WALLET_USES=			bdb:48

ZMQ_CONFIGURE_ENABLE=	zmq
ZMQ_BUILD_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_RUN_DEPENDS=	libzmq4>0:net/libzmq4

GH_ACCOUNT=	litecoin-project

CONFIGURE_ARGS?=	--without-libs \
			--with-gui=qt5 \
			--without-daemon \
			--without-utils

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl" \
		OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}" V=1
MAKE_ENV+=	V=1

PLIST_FILES?=	bin/litecoin-qt man/man1/litecoin-qt.1.gz \
		share/applications/litecoin-qt.desktop share/pixmaps/litecoin128.png

.include <bsd.port.pre.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"

post-patch:
	@${REINPLACE_CMD} -e 's|bitcoin|litecoin|g' \
			  -e 's|Bitcoin|Litecoin|g' \
		${WRKSRC}/contrib/debian/bitcoin-qt.desktop

post-install:
	@${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/litecoin-qt.desktop
	${INSTALL} ${WRKSRC}/share/pixmaps/bitcoin128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/litecoin128.png

.endif

regression-test: build
	# To use this sucessfully, remove --without-daemon and --without-utils
	# from CONFIGURE_ARGS above.

	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.post.mk>
