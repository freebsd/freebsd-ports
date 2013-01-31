# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.0.6
PORTREVISION?=	1
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT?=	Bittorrent client using Qt4 and libtorrent-rasterbar

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		torrent-rasterbar.7:${PORTSDIR}/net-p2p/libtorrent-rasterbar-16

HAS_CONFIGURE=	yes
USE_QT4=	corelib network qmake_build moc_build rcc_build
QT_NONSTANDARD=	yes

MAKE_JOBS_SAFE=	yes

MAN1?=		qbittorrent.1

.if !defined(QB_NOX_SLAVE)
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
USE_QT4+=	gui xml uic_build
INSTALLS_ICONS=	yes
OPTIONS_DEFINE=	DBUS
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
CONFIGURE_ARGS+=	--disable-qt-dbus
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,qputenv,!&,' ${WRKSRC}/src/main.cpp

post-install:
.if !defined(QB_NOX_SLAVE)
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent
.else
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent-nox
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent-nox.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
