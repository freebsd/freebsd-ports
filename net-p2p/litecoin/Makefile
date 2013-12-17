# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	litecoin
PORTVERSION=	0.8.6.1
CATEGORIES=	net-p2p finance
MASTER_SITES=	LOCAL/swills \
		GH

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Virtual Peer-to-Peer Currency Software

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	litecoin-project
GH_COMMIT=	dab8fe6
GH_TAGNAME=	v${PORTVERSION}

USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

USES=		gmake

OPTIONS_DEFINE=	GUI UPNP QRCODES DBUS
OPTIONS_DEFAULT=	GUI QRCODES

GUI_DESC=	Build as a QT4 GUI
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display
DBUS_DESC=	Build with DBUS support

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
USE_QT4=	qmake_build linguist uic moc rcc
BINARY=		litecoin-qt
.else
BINARY=		litecoind
MAKEFILE=	makefile.unix
ALL_TARGET=	${BINARY}
MAKE_ARGS+=	-C ${WRKSRC}/src USE_UPNP=${QMAKE_USE_UPNP}
.endif

PLIST_FILES=	bin/${BINARY}

.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11) && ${PORT_OPTIONS:MQRCODES}
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

.if ${OSVERSION} >= 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-endian
.endif

do-configure:
.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
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
	@${MKDIR} ${PREFIX}/bin
.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${PREFIX}/bin/
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/makefile.unix

regression-test:
.if !${PORT_OPTIONS:MGUI} || defined(WITHOUT_X11)
	@${GMAKE} -C ${WRKSRC}/src -f makefile.unix USE_UPNP=${QMAKE_USE_UPNP} test_litecoin
	(cd ${WRKSRC}/src ; ./test_litecoin)
.endif

.include <bsd.port.post.mk>
