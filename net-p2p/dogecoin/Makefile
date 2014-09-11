# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dogecoin
PORTVERSION=	1.5.0
PORTREVISION=	4
CATEGORIES=	net-p2p finance

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Virtual Peer-to-Peer Currency Client

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	GUI UPNP QRCODES
OPTIONS_DEFAULT=	GUI QRCODES

GUI_DESC=	Build as a QT4 GUI
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	be94b62
GH_TAGNAME=	v${PORTVERSION}

USES=		gmake compiler:c++11-lib
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} <= 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__leveldb__Makefile
.endif

.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
USE_QT4=	corelib network gui qmake_build linguist_build uic_build moc_build rcc_build
BINARY=		dogecoin-qt
.else
BINARY=		dogecoind
ALL_TARGET=	${BINARY} test
MAKE_ARGS+=	-C ${WRKSRC}/src
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
QMAKE_USE_QRCODE=1
.else
QMAKE_USE_QRCODE=0
.endif

PLIST_FILES=	bin/${BINARY}

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

SUB_FILES+=	dogecoin-qt.desktop

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
PLIST_FILES+=	share/applications/dogecoin-qt.desktop share/pixmaps/dogecoin64.png
.endif

post-patch:
.if !${PORT_OPTIONS:MGUI} || defined(WITHOUT_X11)
	@cd ${WRKSRC}/src && ${CP} -p makefile.unix Makefile
	@${REINPLACE_CMD} \
		-e 's|^USE_UPNP.*$$|USE_UPNP=${QMAKE_USE_UPNP}|' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		-e 's:-l dl::' \
		${WRKSRC}/src/Makefile
.endif

do-configure:
.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
	cd ${WRKSRC} && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} \
		QMAKE_LRELEASE=${LRELEASE} INCLUDEPATH=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} dogecoin-qt.pro
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin
.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL} ${WRKDIR}/dogecoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/dogecoin64.png
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${STAGEDIR}${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
