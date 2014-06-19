# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	zetacoin
PORTVERSION=	0.8.99.16
CATEGORIES=	net-p2p finance
MASTER_SITES=	GH

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency with quick transactions

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	X11 UPNP QRCODES
OPTIONS_DEFAULT=	X11 QRCODES
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	9a52761
GH_TAGNAME=	9a52761

USES=		gmake
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
.else
SUB_LIST+=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB+=	X11="@comment "
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
.endif

.if ${PORT_OPTIONS:MX11}
USE_QT4=	corelib gui qmake_build linguist uic moc rcc
BINARY=		${PORTNAME}-qt
PLIST_SUB+=	HEADLESS="@comment "
.else
BINARY=		${PORTNAME}d
MAKE_ARGS+=	-C ${WRKSRC}/src
PLIST_SUB+=	HEADLESS=""
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
QMAKE_USE_QRCODE=1
.else
QMAKE_USE_QRCODE=0
.endif

PLIST_SUB+=	EXECUTABLE="bin/${BINARY}" \
			PORTNAME=${PORTNAME}

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/makefile.unix
.if !${PORT_OPTIONS:MX11}
	@cd ${WRKSRC}/src && ${CP} -p makefile.unix Makefile
	@${REINPLACE_CMD} \
		-e 's|^USE_UPNP.*$$|USE_UPNP=${QMAKE_USE_UPNP}|' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		-e 's:-l dl::' \
		${WRKSRC}/src/Makefile
.endif

do-configure:
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC} && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} \
		QMAKE_LRELEASE=lrelease-qt4 PREFIX=${PREFIX} INCLUDEPATH=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} ${PORTNAME}-qt.pro
.endif

do-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/${BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,zetacoin,g' \
		-e 's,Bitcoin,Zetacoin,g' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${BINARY} ${STAGEDIR}${PREFIX}/bin/${BINARY}
	${INSTALL} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf; \
	fi
.endif

.include <bsd.port.post.mk>
