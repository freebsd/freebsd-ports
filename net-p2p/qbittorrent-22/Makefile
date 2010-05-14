# New ports collection makefile for:	qbittorrent-22
# Date created:				14 February 2010
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
PORTVERSION=	2.2.7
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Bittorrent client using Qt4 and libtorrent-rasterbar

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		GeoIP.5:${PORTSDIR}/net/GeoIP

MAKE_JOBS_SAFE=	yes

CONFLICTS=	qbittorrent-2.1.*

OPTIONS=	NOTIFY "Enable libnotify support" on \
		LT_15 "Use 0.15 version of libtorrent-rasterbar" on

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network xml \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libboost-inc="${LOCALBASE}/include" \
		--with-libboost-lib="${LOCALBASE}/lib"
INSTALLS_ICONS=	yes

MAN1=		qbittorrent.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.if !defined(WITHOUT_LT_15)
LIB_DEPENDS+=	torrent-rasterbar.6:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15
.else
LIB_DEPENDS+=	torrent-rasterbar.5:${PORTSDIR}/net-p2p/libtorrent-rasterbar-14
.endif

BOOSTLIB_PATTERN=	-e 's|\*\-mt\*||'

post-patch:
	@${REINPLACE_CMD} -e 's|$$$$PREFIX/share/man|${MANPREFIX}/man|' \
		${WRKSRC}/src/src.pro
	@${ECHO_CMD} "LIBS+= -lexecinfo" >> ${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${BOOSTLIB_PATTERN} \
		${WRKSRC}/configure
	@${REINPLACE_CMD} ${BOOSTLIB_PATTERN} ${WRKSRC}/qcm/libboost.qcm

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent

.include <bsd.port.post.mk>
