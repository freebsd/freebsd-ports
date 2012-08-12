# New ports collection makefile for:	qbittorrent
# Date created:				11 August 2012
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.0.0
PORTREVISION?=	0
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	dougb@FreeBSD.org
COMMENT?=	Bittorrent client using Qt4 and libtorrent-rasterbar

# lib versions specified on purpose
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		torrent-rasterbar.6:${PORTSDIR}/net-p2p/libtorrent-rasterbar-16

MAKE_JOBS_SAFE=	yes

CONFLICTS=	qbittorrent-2.* qbittorrent-4.[0-9].*

USE_QT4=	corelib network qmake_build moc_build rcc_build

.if !defined(QB_NOX_SLAVE)
.if defined(WITHOUT_X11)
BROKEN=	Use net-p2p/${PORTNAME}-nox11 for the non-GUI version
.endif
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
OPTIONS=	DBUS "Enable dbus support" off
USE_QT4+=	gui xml uic_build
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes

MAN1?=		qbittorrent.1

.include <bsd.port.pre.mk>

.if defined(WITH_DBUS)
USE_QT4+=		dbus
.else
CONFIGURE_ARGS+=	--disable-qt-dbus
.endif

post-install:
.if !defined(QB_NOX_SLAVE)
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent
	@${CAT} ${PKGMESSAGE}
.else
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent-nox
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent-nox.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
