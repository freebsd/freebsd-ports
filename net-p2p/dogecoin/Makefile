# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dogecoin
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	net-p2p finance

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Virtual Peer-to-Peer Currency Client

LICENSE=	MIT

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to configure: "Big Endian not supported"

OPTIONS_DEFINE=	GUI UPNP QRCODES
OPTIONS_DEFAULT=	GUI QRCODES

GUI_DESC=	Build as a QT4 GUI
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display

USE_GITHUB=	yes

USES=		bdb:5 gmake compiler:c++11-lib pkgconfig autoreconf ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-incompatible-bdb \
		SSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" SSL_LIBS="-lssl" \
		CRYPTO_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" CRYPTO_LIBS="-lcrypto"
CONFIGURE_ENV+=	OBJC="${CC}" OBJCFLAGS="${CFLAGS}" OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} \
		-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

PLIST_FILES=	bin/dogecoind bin/dogecoin-cli

.include <bsd.port.options.mk>

#.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
#EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__leveldb__Makefile
#.endif

GUI_CONFIGURE_ENABLE=		gui
.if ${PORT_OPTIONS:MGUI}
USE_QT4=	corelib network gui qmake_build linguist_build uic_build moc_build rcc_build dbus
PLIST_FILES+=	share/applications/dogecoin-qt.desktop \
		share/pixmaps/dogecoin64.png \
		bin/dogecoin-qt
.endif

QRCODES_CONFIGURE_ENABLE=	qrencode
.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:graphics/libqrencode
.endif

UPNP_CONFIGURE_ENABLE=		miniupnpc
.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:net/miniupnpc
.endif

SUB_FILES+=	dogecoin-qt.desktop

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dogecoind      ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/dogecoin-cli   ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/src/qt/dogecoin-qt ${STAGEDIR}${PREFIX}/bin/
	${INSTALL} ${WRKDIR}/dogecoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/dogecoin64.png
.endif

.include <bsd.port.post.mk>
