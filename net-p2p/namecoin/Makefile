# Created by: Chad J. Milios <milios@ccsys.com>
# $FreeBSD$

PORTNAME=	namecoin
PORTVERSION=	Q.3.72
PORTREVISION=	2
CATEGORIES=	net-p2p dns
MASTER_SITES=	GH

MAINTAINER=	milios@ccsys.com
COMMENT=	Decentralized, open DNS system and general purpose key/value store

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	X11 UPNP QRCODES DBUS
OPTIONS_DEFAULT=	X11 QRCODES

UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display

USE_GITHUB=	yes
GH_ACCOUNT=	namecoinq
GH_PROJECT=	namecoinq
GH_COMMIT=	cdf052b
GH_TAGNAME=	v${PORTVERSION}

USES=		gmake compiler:c++11-lib
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_QT4=	corelib network gui qmake_build linguist_build uic_build moc_build rcc_build

BINARY=		namecoin-qt
LIB_DEPENDS+=	libprotobuf.so:${PORTSDIR}/devel/protobuf
.else
BINARY=		namecoind
MAKE_ARGS+=	-C ${WRKSRC}/src
USE_GNOME=	glib20
.endif

.if ${PORT_OPTIONS:MQRCODES}
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

PLIST_FILES+=	bin/${BINARY}

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

.include <bsd.port.pre.mk>

post-patch:
.if !${PORT_OPTIONS:MX11}
	@cd ${WRKSRC}/src && ${CP} ${FILESDIR}/makefile.unix Makefile
	@${REINPLACE_CMD} \
		-e 's|^USE_UPNP.*$$|USE_UPNP=${QMAKE_USE_UPNP}|' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/Makefile
.endif

do-configure:
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC} && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} \
		QMAKE_LRELEASE=${LRELEASE} INCLUDEPATH+=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} ${BINARY}.pro
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${STAGEDIR}${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
