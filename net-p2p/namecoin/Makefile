# Created by: Chad J. Milios <milios@ccsys.com>
# $FreeBSD$

PORTNAME=	namecoin
PORTVERSION=	0.19.0.1
DISTVERSIONPREFIX=	nc
PORTEPOCH=	1
CATEGORIES=	net-p2p dns

MAINTAINER=	milios@ccsys.com
COMMENT?=	Decentralized, open DNS and general purpose key/value store

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libevent.so:devel/libevent

CONFLICTS_INSTALL=	namecoin-beta-[0-9]* namecoin-beta-daemon-[0-9]* namecoin-beta-utils-[0-9]* \
		namecoin-stable-[0-9]* namecoin-stable-daemon-[0-9]* namecoin-stable-utils-[0-9]*

USES=		autoreconf compiler:c++11-lib gmake libtool pkgconfig ssl
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	indolering:graphics
GH_PROJECT=	namecoin-core namecoin-graphics:graphics
GH_TAGNAME=	a13a73b:graphics

SLAVE_PORT?=	no

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils qt:5
USE_QT=		core buildtools gui linguisttools_build network qmake_build xml widgets

BUILD_DEPENDS+=	protoc:devel/protobuf \
		svg2png:graphics/svg2png
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
	${LOCALBASE}/bin/svg2png -w128 -h128 ${WRKSRC_graphics}/svg/namecoin-logo.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/namecoin128.png

.endif

regression-test: build
	# To use this sucessfully, remove --without-daemon and --without-utils
	# from CONFIGURE_ARGS above.

	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
