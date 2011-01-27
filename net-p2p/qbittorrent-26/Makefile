# New ports collection makefile for:	qbittorrent-26
# Date created:				10 January 2011
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
PORTVERSION=	2.6.4
PORTREVISION?=	0
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	dougb@FreeBSD.org
COMMENT?=	Bittorrent client using Qt4 and libtorrent-rasterbar

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		torrent-rasterbar.5:${PORTSDIR}/net-p2p/libtorrent-rasterbar-14

MAKE_JOBS_SAFE=	yes

CONFLICTS=	qbittorrent-2.[2345789].*

USE_QT_VER=	4
QT_COMPONENTS=	corelib network qmake_build moc_build rcc_build

.if !defined(QB26_NOX_SLAVE)
.if defined(WITHOUT_X11)
BROKEN=	Use net-p2p/${PORTNAME}-nox11 for the non-GUI version
.endif
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
OPTIONS=	NOTIFY "Enable libnotify support" on
QT_COMPONENTS+=	gui xml uic_build dbus
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes

MAN1?=		qbittorrent.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

post-install:
.if !defined(QB26_NOX_SLAVE)
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent
.else
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent-nox
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent-nox.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
