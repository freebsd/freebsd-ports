# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitcoin
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=	v
PORTREVISION?=	1
CATEGORIES=	net-p2p finance

MAINTAINER=	robbak@robbak.com
COMMENT?=	Virtual Peer-to-Peer Currency Client (QT)

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

USES=		autoreconf compiler:c++0x gmake libtool pkgconfig shebangfix
SHEBANG_FILES=	src/test/*.py
USE_GITHUB=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

SLAVE_PORT?=	no

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils
USE_QT4=	corelib gui moc_build linguisttools_build network qmake_build \
		rcc_build uic_build

BUILD_DEPENDS+=	protoc:${PORTSDIR}/devel/protobuf
LIB_DEPENDS+=	libprotobuf.so:${PORTSDIR}/devel/protobuf

TESTS_USE=		QT4=testlib
TESTS_PLIST_FILES=	%%QT_BINDIR%%/test_bitcoin-qt \
			bin/test_bitcoin
.endif

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS UPNP WALLET
OPTIONS_DEFAULT?=	HARDENING QRCODES WALLET
OPTIONS_SUB=		yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support

DBUS_CONFIGURE_WITH=	qtdbus
DBUS_USE=		QT4=dbus

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

HARDENING_CONFIGURE_ENABLE=	hardening

TESTS_CONFIGURE_ENABLE=	tests
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "yes"
TESTS_PLIST_FILES=	bin/test_bitcoin
.endif

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=		-L${LOCALBASE}/lib

QRCODES_CONFIGURE_WITH=	qrencode
QRCODES_LIB_DEPENDS=	libqrencode.so:${PORTSDIR}/graphics/libqrencode

WALLET_CONFIGURE_ENABLE=	wallet
WALLET_CXXFLAGS=		-I${BDB_INCLUDE_DIR}
WALLET_LIBS=			-L${BDB_LIB_DIR}
WALLET_USE=			BDB=48

GH_ACCOUNT=	bitcoin

CONFIGURE_ARGS?=	--without-libs \
			--disable-reduce-exports \
			--with-gui \
			--without-daemon \
			--without-utils

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl"
MAKE_ENV+=	V=1

PLIST_FILES?=	bin/bitcoin-qt share/applications/bitcoin-qt.desktop \
		share/pixmaps/bitcoin128.png

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"

post-install:
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/share/pixmaps/bitcoin128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.endif

regression-test: build
	# To use this sucessfully, remove --without-daemon and --without-utils
	# from CONFIGURE_ARGS above.

	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
