# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dogecoin
PORTVERSION=	1.3
CATEGORIES=	net-p2p finance
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~swills/ \
		GH

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
GH_ACCOUNT=	dogecoin
GH_PROJECT=	dogecoin
GH_COMMIT=	2ee5cb3
GH_TAGNAME=	${GH_COMMIT}

USES=		gmake compiler:c++11-lib
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
USE_QT4=	corelib gui qmake_build linguist uic moc rcc
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

.include <bsd.port.pre.mk>

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
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} \
		QMAKE_LRELEASE=${LRELEASE} INCLUDEPATH=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} dogecoin-qt.pro
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin
.if ${PORT_OPTIONS:MGUI} && !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
