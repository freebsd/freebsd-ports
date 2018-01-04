# Created by: Chad J. Milios <milios@ccsys.com>
# $FreeBSD$

PORTNAME=	namecoin
PORTVERSION=	0.3.80
DISTVERSIONPREFIX=	nc
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	net-p2p dns

MAINTAINER=	milios@ccsys.com
COMMENT=	Decentralized, open DNS and general purpose key/value store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

BROKEN_powerpc64=	fails to build: util.cpp: undefined reference to boost::program_options::to_internal

OPTIONS_DEFINE=	X11 UPNP QRCODES DBUS
OPTIONS_DEFAULT=	X11 QRCODES

QRCODES_DESC=	QR code display support

USE_GITHUB=	yes

USES=		bdb:48 gmake compiler:c++11-lib ssl
MAKE_JOBS_UNSAFE=yes

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_QT4=	corelib network gui qmake_build linguist_build uic_build moc_build rcc_build

BINARY=		namecoin-qt
LIB_DEPENDS+=	libprotobuf.so:devel/protobuf
.else
BINARY=		namecoind
MAKE_ARGS+=	-C ${WRKSRC}/src
USE_GNOME=	glib20
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:graphics/libqrencode
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
LIB_DEPENDS+=	libminiupnpc.so:net/miniupnpc
CXXFLAGS+=	-I${LOCALBASE}/include/miniupnpc
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
