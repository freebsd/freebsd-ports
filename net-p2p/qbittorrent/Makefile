# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.1.2
PORTREVISION?=	0
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT?=	Bittorrent client using Qt4 and libtorrent-rasterbar

LICENSE=	GPLv2

# ABI versions specified on purpose for libtorrent-rasterbar
LIB_DEPENDS=	libtorrent-rasterbar.so:${PORTSDIR}/net-p2p/libtorrent-rasterbar \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		pkgconfig
USE_QT4=	corelib network qmake_build linguist_build moc_build rcc_build uic_build
QT_NONSTANDARD=	yes
DESTDIRNAME=	INSTALL_ROOT

.if !defined(SLAVE_PORT)
LIB_DEPENDS+=	libGeoIP.so:${PORTSDIR}/net/GeoIP
USE_QT4+=	gui xml
INSTALLS_ICONS=	yes
OPTIONS_DEFINE=	DBUS
.endif

PORTDOCS=	AUTHORS Changelog README TODO

OPTIONS_DEFINE=	DOCS DBUS

DBUS_CONFIGURE_ENABLE=	qt-dbus

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.endif

do-configure:
.if defined(SLAVE_PORT) && ${SLAVE_PORT:L} == "no"
	@cd ${WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX}
.else
	@cd ${WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX} --disable-gui
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L} == "no"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
.else
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent-nox
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent-nox.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
