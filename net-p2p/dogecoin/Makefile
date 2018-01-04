# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dogecoin
PORTVERSION=	1.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-p2p finance

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	P2P crypto currency client favored by shiba inus worldwide

LICENSE=	MIT

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to configure: "Big Endian not supported"

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf

USES=		autoreconf bdb compiler:gcc-c++11-lib gmake libtool \
		localbase:ldconfig pkgconfig ssl
USE_CXXSTD=	c++11
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes

OPTIONS_DEFINE=	GUI UPNP UTILS QRCODES
OPTIONS_DEFAULT=GUI UPNP UTILS QRCODES

GUI_DESC=	Build as a QT5 GUI
UPNP_DESC=	Build with UPNP support
UTILS_DESC=	Build with additional cli utils
QRCODES_DESC=	Build with QR code display

CONFIGURE_ARGS+=	--with-incompatible-bdb --disable-tests

GUI_CONFIGURE_ARGS=	--with-gui=qt5
GUI_CONFIGURE_OFF=	--with-gui=no
GUI_USE=		QT5=buildtools,core,dbus,gui,linguist_build,network,printsupport,testlib,widgets
GUI_USES=		desktop-file-utils

QRCODES_CONFIGURE_WITH=	qrencode
QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc

UTILS_CONFIGURE_WITH=	utils

CONFIGURE_ENV=	SSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" SSL_LIBS="-lssl" \
		CRYPTO_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" CRYPTO_LIBS="-lcrypto"

CXXFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}

SUB_FILES=	dogecoin-qt.desktop

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbitcoinconsensus.so.0.0.0

post-install-GUI-on:
	${INSTALL} ${WRKDIR}/dogecoin-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/dogecoin64.png

.include <bsd.port.mk>
