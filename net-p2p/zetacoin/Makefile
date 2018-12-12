# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	zetacoin
PORTVERSION=	0.11.2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	25
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency with quick transactions

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES+=		autoreconf compiler:c++11-lang gmake libtool pkgconfig:build ssl
USE_CXXSTD=	c++11
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

BROKEN_armv6=		AtomicPointer not implemented
BROKEN_powerpc64=	fails to configure: No working boost sleep implementation found

USE_GITHUB=	yes

OPTIONS_DEFINE=	X11 UPNP WALLET CLI TEST
OPTIONS_SUB=	yes

WALLET_DESC=	Build wallet or P2P server node only
QRCODES_DESC=	Enable QR code display when building graphical interface
CLI_DESC=		Build command line RPC client

OPTIONS_DEFAULT=	WALLET
OPTIONS_GROUP=		X11
OPTIONS_GROUP_X11=	QRCODES

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=		-L${LOCALBASE}/lib

X11_CONFIGURE_WITH=	gui
X11_CONFIGURE_ON=	--without-daemon
X11_CONFIGURE_OFF=	--with-daemon
X11_BUILD_DEPENDS=	protoc:devel/protobuf
X11_LIB_DEPENDS=	libprotobuf.so:devel/protobuf
X11_USE=		qt=corelib,network,gui,qmake_build,linguisttools_build \
			qt=uic_build,moc_build,rcc_build,qtestlib_build
X11_USES=		desktop-file-utils qmake:no_env qt:4

WALLET_CONFIGURE_ENABLE=wallet
WALLET_CXXFLAGS=	-I${BDB_INCLUDE_DIR}
WALLET_LIBS=		-L${BDB_LIB_DIR}
WALLET_USES=		bdb:48

QRCODES_IMPLIES=	X11
QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODES_CONFIGURE_WITH=	qrencode

CLI_CONFIGURE_WITH=	cli

TEST_CONFIGURE_ENABLE=	tests
TEST_ALL_TARGET=	check

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl" \
		OBJC="${CC}" OBJCFLAGS="${CFLAGS}" OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"

QT_BINARY=	${PORTNAME}-qt
CLI_BINARY=	${PORTNAME}-cli
DAEMON=		${PORTNAME}d

PLIST_SUB+=	EXECUTABLE_QT=bin/${QT_BINARY} \
		EXECUTABLE_CLI=bin/${CLI_BINARY} \
		EXECUTABLE_DAEMON=bin/${DAEMON} \
		PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

# tests will currently fail
.if ${PORT_OPTIONS:MTEST}
BROKEN=	automated testing fails
.endif

.if ! ${PORT_OPTIONS:MX11}
USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
.else
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
# The configure script will output this message, so save the user the trouble
IGNORE=	detected LibreSSL: This is NOT supported, and may break consensus compatibility!
.endif

post-patch:
	${MKDIR} ${WRKSRC}/src/build-aux

do-install:
	@${DO_NADA}

do-install-CLI-on:
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${CLI_BINARY} ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}

do-install-X11-on:
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/qt/${QT_BINARY} ${STAGEDIR}${PREFIX}/bin/${QT_BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,zetacoin,g' \
		-e 's,Bitcoin,Zetacoin,g' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-X11-off:
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${DAEMON} ${STAGEDIR}${PREFIX}/bin/${DAEMON}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.post.mk>
