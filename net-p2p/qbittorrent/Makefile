# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.2.3
DISTVERSIONPREFIX=	release-
CATEGORIES=	net-p2p ipv6

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Bittorrent client using Qt4 and libtorrent-rasterbar

LICENSE=	GPLv2

# ABI versions specified on purpose for libtorrent-rasterbar
LIB_DEPENDS=	libtorrent-rasterbar.so:${PORTSDIR}/net-p2p/libtorrent-rasterbar \
		libboost_system.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	qBittorrent
GH_PROJECT=	qBittorrent

USES=		compiler:c++11-lang execinfo pkgconfig tar:xz
USE_QT4=	corelib network qmake_build linguisttools_build moc_build \
		rcc_build uic_build
QT_NONSTANDARD=	yes
DESTDIRNAME=	INSTALL_ROOT

.if !defined(SLAVE_PORT)
LIB_DEPENDS+=	libGeoIP.so:${PORTSDIR}/net/GeoIP
USES+=		desktop-file-utils
USE_QT4+=	gui xml
INSTALLS_ICONS=	yes
OPTIONS_DEFINE=	DBUS
.endif

PORTDOCS=	AUTHORS Changelog README.md

OPTIONS_DEFINE=	DEBUG DOCS DBUS

DEBUG_CONFIGURE_ENABLE=	debug
DBUS_CONFIGURE_ENABLE=	qt-dbus
DBUS_USE=		QT4=dbus
CONFIGURE_ENV+=		zlib_CFLAGS=-I/usr/include
CONFIGURE_ENV+=		zlib_LIBS=-lz
CONFIGURE_ARGS+=	CXXFLAGS=-DBOOST_ASIO_DYN_LINK

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

post-patch:
	${REINPLACE_CMD} 's,^\$$QT_QMAKE,${LOCALBASE}/bin/qmake-qt4,'	\
	    ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.options.mk>

.if !defined(SLAVE_PORT) || ${SLAVE_PORT:tl} != "no"
CONFIGURE_ARGS+=	--disable-gui
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

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

.include <bsd.port.mk>
