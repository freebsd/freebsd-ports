PORTNAME=	namecoin
DISTVERSIONPREFIX=	nc
DISTVERSION=	24.0
PORTREVISION=	18
PORTEPOCH=	1
CATEGORIES=	net-p2p dns
MASTER_SITES+=	https://same.name/static/:icon
DISTFILES+=	namecoin128.c99d628dd26b.png:icon
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	milios@ccsys.com
COMMENT?=	Decentralized, open DNS and general purpose key/value store
WWW=		https://namecoin.org/

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libevent.so:devel/libevent

USES=		autoreconf compiler:c++17-lang gmake libtool pkgconfig ssl
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_PROJECT=	namecoin-core

SLAVE_PORT?=	no

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils qt:5
USE_QT=		core buildtools gui linguisttools:build network qmake:build xml widgets

BUILD_DEPENDS+=	protoc:devel/protobuf
LIB_DEPENDS+=	libprotobuf.so:devel/protobuf

TESTS_USES=		qt:5
TESTS_USE=		QT=testlib
TESTS_PLIST_FILES=	bin/test_namecoin-qt \
			bin/test_namecoin
.endif

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT?=	DBUS HARDENING QRCODES UPNP WALLET
OPTIONS_SUB=		yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support
ZMQ_DESC=	Block and transaction broadcasting with ZeroMQ

DBUS_CONFIGURE_WITH=	qtdbus
DBUS_USES=		qt:5
DBUS_USE=		QT=dbus

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

HARDENING_CONFIGURE_ENABLE=	hardening

TESTS_CONFIGURE_ENABLE=	tests bench
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "yes"
TESTS_PLIST_FILES=	bin/test_namecoin
.endif
TESTS_PLIST_FILES+=	bin/bench_namecoin

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_USES=		localbase

QRCODES_CONFIGURE_WITH=	qrencode
QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

WALLET_CONFIGURE_OFF=	--disable-wallet
WALLET_CONFIGURE_ON=	--enable-wallet \
			--with-sqlite=no \
			--with-incompatible-bdb \
			BDB_CFLAGS=-I${BDB_INCLUDE_DIR} \
			BDB_LIBS="-L${BDB_LIB_DIR} \
			-Wl,-rpath=${BDB_LIB_DIR} -l${BDB_LIB_CXX_NAME}"
WALLET_USES=		bdb:5+

ZMQ_CONFIGURE_ENABLE=	zmq
ZMQ_BUILD_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_RUN_DEPENDS=	libzmq4>0:net/libzmq4

CONFIGURE_ARGS?=	--without-libs \
			--with-gui=qt5 \
			--without-daemon \
			--without-utils \
			--disable-man

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl" \
		OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	V=1

PLIST_FILES?=	bin/namecoin-qt share/applications/namecoin-qt.desktop \
		share/pixmaps/namecoin128.png

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"

post-install:
	${INSTALL_DATA} ${FILESDIR}/namecoin-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${DISTDIR}/namecoin128.c99d628dd26b.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/namecoin128.png

.endif

regression-test: build
	# To use this sucessfully, remove --without-daemon and --without-utils
	# from CONFIGURE_ARGS above.

	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
