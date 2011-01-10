# New ports collection makefile for:	qbittorrent-26
# Date created:				10 January 2011
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
PORTVERSION=	2.6.0
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PKGNAME}/

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Bittorrent client using Qt4 and libtorrent-rasterbar

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		torrent-rasterbar.5:${PORTSDIR}/net-p2p/libtorrent-rasterbar-14 \
		GeoIP.5:${PORTSDIR}/net/GeoIP

MAKE_JOBS_SAFE=	yes

CONFLICTS=	qbittorrent-2.[2345789].*

OPTIONS=	NOTIFY "Enable libnotify support" on

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network xml \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

MAN1=		qbittorrent.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$$$PREFIX/share/man|${MANPREFIX}/man|' \
		${WRKSRC}/unixconf.pri
	@${ECHO_CMD} "LIBS+= -lexecinfo" >> ${WRKSRC}/src/src.pro

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent

.include <bsd.port.post.mk>
