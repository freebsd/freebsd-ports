# New ports collection makefile for:		bitcoin
# Date created:					2011-05-20
# Whom:						Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitcoin
PORTVERSION=	0.6.3
PORTREVISION=	3
CATEGORIES=	net-p2p finance

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Peer-to-Peer Currency Client

LIB_DEPENDS=	boost_date_time:${PORTSDIR}/devel/boost-libs

OPTIONS=	GUI  "Build with QT3 GUI" on	\
		UPNP "Build with UPNP support"  off \
		QRCODES "Build with QR code display" on

USE_GITHUB=     yes
GH_ACCOUNT=     bitcoin
GH_PROJECT=	bitcoin
GH_COMMIT=      6e0c5e3

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	47

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

.if defined(WITH_GUI) && !defined(WITHOUT_X11)
USE_QT_VER=	4
USE_QT4=	corelib gui qmake_build linguist uic moc rcc
BINARY=		bitcoin-qt
.else
BINARY=		bitcoind
ALL_TARGET=	${BINARY}
MAKE_ARGS+=	-C ${WRKSRC}/src
.endif

.if defined(WITH_QRCODES)
LIB_DEPENDS+=	qrencode:${PORTSDIR}/graphics/libqrencode
QMAKE_USE_QRCODE=1
.else
QMAKE_USE_QRCODE=0
.endif

PLIST_FILES=	bin/${BINARY}

.if defined(WITH_UPNP)
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${CP} ${WRKSRC}/src/protocol.h ${WRKSRC}/src/protocol.h.orig
	@${AWK} 'BEGIN { f = 0 } { if ( $$0 ~ /^#include/ && f == 0 ) { f = 1; print "#include <sys/socket.h>"; print "#include <netinet/in.h>" }; print }' \
		${WRKSRC}/src/protocol.h.orig > ${WRKSRC}/src/protocol.h

	@cd ${WRKSRC}/src && ${CP} -p makefile.unix Makefile
	@${REINPLACE_CMD} \
		-e 's|wx-config|${WX_CONFIG}|g' \
		-e 's|^CXXFLAGS=.*$$|CXXFLAGS += $$(DEFS)|' \
		-e 's|^USE_UPNP.*$$||' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		-e 's:-O3::' -e 's:-\(march=[A-Za-z0-9]*\)::g' \
		-e 's:-l dl::' \
		${WRKSRC}/src/Makefile

do-configure:
.if defined(WITH_GUI) && !defined(WITHOUT_X11)
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} \
		QMAKE_LRELEASE=lrelease-qt4 PREFIX=${PREFIX} INCLUDEPATH=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} bitcoin-qt.pro
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin
.if defined(WITH_GUI) && !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
