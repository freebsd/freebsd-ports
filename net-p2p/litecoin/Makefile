# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	litecoin
PORTVERSION=	0.10.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-p2p finance
MASTER_SITES=	LOCAL/swills

MAINTAINER=	swills@FreeBSD.org
COMMENT?=	Virtual Peer-to-Peer Currency Client (QT)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES+=		autoreconf gmake libtool pkgconfig shebangfix ssl
SHEBANG_FILES=	src/test/*.py
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

SLAVE_PORT?=	no

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		cpe desktop-file-utils
USE_QT4=	corelib gui moc_build linguisttools_build network qmake_build \
		rcc_build uic_build
CPE_VENDOR=	bitcoin
CPE_PRODUCT=	bitcoin-qt
CPE_VERSION=	${PORTVERSION:R}

BUILD_DEPENDS+=	protoc:devel/protobuf
LIB_DEPENDS+=	libprotobuf.so:devel/protobuf

DBUS_USE=		QT4=dbus

TESTS_USE=		QT4=testlib
TESTS_PLIST_FILES=	bin/test_litecoin-qt
.endif

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS UPNP WALLET
OPTIONS_DEFAULT?=	HARDENING QRCODES WALLET
OPTIONS_SUB=		yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support

DBUS_CONFIGURE_WITH=	qtdbus

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

HARDENING_CONFIGURE_ENABLE=	hardening

TESTS_CONFIGURE_ENABLE=	tests
TESTS_PLIST_FILES+=	bin/test_litecoin

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

GH_ACCOUNT=	litecoin-project

CONFIGURE_ARGS?=	--without-libs \
			--disable-reduce-exports \
			--with-gui \
			--without-daemon \
			--without-utils

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl"

CONFIGURE_ENV+= OBJC="${CC}" OBJCFLAGS="${CFLAGS}" OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"

CPPFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES?=	bin/litecoin-qt share/applications/litecoin-qt.desktop \
		share/pixmaps/litecoin128.png

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
# The configure script will output this message, so save the user the trouble
IGNORE=	Detected LibreSSL: This is NOT supported, and may break consensus compatibility!
.endif

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
