# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitcoin
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	net-p2p finance
MASTER_SITES=	http://vps.robbak.com/distfiles/ \
		${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~swills/ \
		GH

MAINTAINER=	robbak@robbak.com
COMMENT=	Virtual Peer-to-Peer Currency Client

LICENSE=	MIT

BUILD_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf \
				pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	GUI WALLET UPNP QRCODES
OPTIONS_DEFAULT=	GUI WALLET QRCODES

GUI_DESC=	Build and install the QT4 binary
WALLET_DESC=	Build with support to create and manage a wallet
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display

AUTOMAKE_ARGS+=	--add-missing
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
#ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
CONFIGURE_ENV=	SSL_LIBS="-lssl" CRYPTO_LIBS="-lcrypto" SSL_CFLAGS="-I/usr/include" CRYPTO_CFLAGS="-I/usr/include"

USE_GITHUB=	yes
GH_ACCOUNT=	bitcoin
GH_PROJECT=	bitcoin
GH_COMMIT=		30a7357
GH_TAGNAME=	v${PORTVERSION}

USES=			gmake
USE_OPENSSL=	yes
USE_BDB=		yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--disable-tests

.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
USE_QT4=	corelib gui qmake_build linguist uic moc rcc qtestlib_build
USES+=		desktop-file-utils
PLIST_FILES=	%%QT_BINDIR%%/bitcoin-qt %%QT_BINDIR%%/bitcoind %%QT_BINDIR%%/bitcoin-cli
PLIST_FILES+=	share/applications/bitcoin-qt.desktop share/pixmaps/bitcoin128.png
CONFIGURE_ARGS+=--with-gui
.else
PLIST_FILES=		bin/bitcoind bin/bitcoin-cli
CONFIGURE_ARGS+=--without-gui
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
CONFIGURE_ARGS+=--with-qrencode
.else
CONFIGURE_ARGS+=--without-qrencode
.endif

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
CONFIGURE_ARGS+=--with-miniupnpc
.else
CONFIGURE_ARGS+=--without-miniupnpc
.endif

.if ${PORT_OPTIONS:MWALLET}
CONFIGURE_ARGS+=--enable-wallet
.else
CONFIGURE_ARGS+=--disable-wallet
.endif

.include <bsd.port.pre.mk>

post-patch:
	${MKDIR} ${WRKSRC}/src/build-aux

post-install:
.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/share/pixmaps/bitcoin128.png ${STAGEDIR}${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.post.mk>
