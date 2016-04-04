# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.3.3
DISTVERSIONPREFIX=	release-
CATEGORIES=	net-p2p ipv6

MAINTAINER=	yuri@rawbw.com
COMMENT?=	Bittorrent client using Qt4 and libtorrent-rasterbar

LICENSE=	GPLv2

# ABI versions specified on purpose for libtorrent-rasterbar
LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		libboost_system.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	qBittorrent
GH_PROJECT=	qBittorrent

USES=		compiler:c++11-lang execinfo pkgconfig tar:xz
QT4_USE=	QT4=corelib,network,qmake_build,linguisttools_build,moc_build,rcc_build,uic_build
QT5_USE=	QT5=core,concurrent,network,widgets,qmake_build,buildtools_build,linguisttools_build
QT_NONSTANDARD=	yes
DESTDIRNAME=	INSTALL_ROOT

.if !defined(SLAVE_PORT)
LIB_DEPENDS+=	libGeoIP.so:net/GeoIP
USES+=		desktop-file-utils
QT4_USE+=	QT4=gui,xml
QT5_USE+=	QT5=gui,xml
INSTALLS_ICONS=	yes
OPTIONS_DEFINE=	DBUS
.endif

PORTDOCS=	AUTHORS Changelog README.md

OPTIONS_DEFINE=		DEBUG DOCS DBUS
OPTIONS_RADIO=		QT
OPTIONS_RADIO_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT4
OPTION_QT=		${SELECTED_OPTIONS:MQT*}

DEBUG_CONFIGURE_ENABLE=	debug
DBUS_CONFIGURE_ENABLE=	qt-dbus

.include <bsd.port.options.mk>

# Qt4 fails to detect base clang features, this section corrects it
.if ${PORT_OPTIONS:MQT4}
CXXFLAGS+=		-DQ_COMPILER_INITIALIZER_LISTS
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_${OPTION_QT}+=	dbus
.endif

CXXFLAGS+=		-DBOOST_ASIO_DYN_LINK
CONFIGURE_ENV+=		zlib_CFLAGS=-I/usr/include
CONFIGURE_ENV+=		zlib_LIBS=-lz
CONFIGURE_ARGS+=	CXXFLAGS="${CXXFLAGS}"
CONFIGURE_ARGS+=	--with-${OPTION_QT:tl}

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

post-patch:
.if ${PORT_OPTIONS:MQT4}
	${REINPLACE_CMD} 's,^\$$QT_QMAKE,${LOCALBASE}/bin/qmake-qt4,'	\
	    ${WRKSRC}/${CONFIGURE_SCRIPT}
.else
	${REINPLACE_CMD} 's,^\$$QT_QMAKE,${LOCALBASE}/lib/qt5/bin/qmake,'	\
	    ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.if !defined(SLAVE_PORT) || ${SLAVE_PORT:tl} != "no"
CONFIGURE_ARGS+=	--disable-gui
.endif

post-install:
.if defined(SLAVE_PORT) && ${SLAVE_PORT:tl} == "no"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
.else
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent-nox
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent-nox.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
.endif
	@${RM} -rf ${STAGEDIR}${PREFIX}/share/man

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
