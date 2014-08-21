# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	litecoin
PORTVERSION=	0.8.6.2
PORTREVISION=	1
CATEGORIES=	net-p2p finance
MASTER_SITES=	LOCAL/swills \
		GH

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Virtual Peer-to-Peer Currency Software

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	litecoin-project
GH_COMMIT=	fa2cfea
GH_TAGNAME=	v${PORTVERSION}

USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

USES=		gmake

OPTIONS_DEFINE=	X11 UPNP QRCODES DBUS
OPTIONS_DEFAULT=	X11 QRCODES

UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display
DBUS_DESC=	Build with DBUS support

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

.if ${PORT_OPTIONS:MX11}
USE_QT4=	network gui qmake_build linguist_build uic_build moc_build rcc_build

BINARY=		litecoin-qt
.else
BINARY=		litecoind
MAKEFILE=	makefile.unix
ALL_TARGET=	${BINARY}
MAKE_ARGS+=	-C ${WRKSRC}/src USE_UPNP=${QMAKE_USE_UPNP}
.endif

PLIST_FILES=	bin/${BINARY}

.if ${PORT_OPTIONS:MX11} && ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
QMAKE_USE_QRCODE=1
.else
QMAKE_USE_QRCODE=0
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
QMAKE_USE_DBUS=	1
.else
QMAKE_USE_DBUS=	0
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MX11}
PLIST_FILES+=	share/applications/litecoin-qt.desktop share/pixmaps/litecoin64.png
.endif

do-configure:
.if ${PORT_OPTIONS:MX11}
	cd ${BUILD_WRKSRC} && \
		${QMAKE} ${QMAKE_ARGS} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} \
		QMAKE_LRELEASE=${LRELEASE} \
		USE_UPNP=${QMAKE_USE_UPNP} \
		USE_QRCODE=${QMAKE_USE_QRCODE} \
		USE_DBUS=${QMAKE_USE_DBUS} \
		bitcoin-qt.pro
.endif

do-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,litecoin,g' \
		-e 's,Bitcoin,Litecoin,g' \
		-e 's,128,64,g' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/litecoin-qt.desktop
	${INSTALL} ${WRKSRC}/share/pixmaps/bitcoin64.png ${STAGEDIR}${PREFIX}/share/pixmaps/litecoin64.png
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${STAGEDIR}${PREFIX}/bin/
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/makefile.unix

regression-test:
.if !${PORT_OPTIONS:MX11}
	@${MAKE_CMD} -C ${WRKSRC}/src -f makefile.unix USE_UPNP=${QMAKE_USE_UPNP} test_litecoin
	(cd ${WRKSRC}/src ; ./test_litecoin)
.endif

.include <bsd.port.post.mk>
