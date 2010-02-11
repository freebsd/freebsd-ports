# New ports collection makefile for:	qbittorrent
# Date created:				2007-04-01
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
PORTVERSION=	2.1.5
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Bittorrent client written in C++ / Qt4 using libtorrent

BUILD_DEPENDS=	${LOCALBASE}/share/GeoIP/GeoIP.dat:${PORTSDIR}/net/GeoIP
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		torrent-rasterbar.5:${PORTSDIR}/net-p2p/rblibtorrent-devel
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=	yes

OPTIONS=	NOTIFY "Enable libnotify support" on

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network xml \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libboost-inc="${LOCALBASE}/include"
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
		${WRKSRC}/src/src.pro
	@${ECHO_CMD} "LIBS+= -lexecinfo" >> ${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|@BOOST_SYSTEM_LIB@|-lboost_system|' \
		${WRKSRC}/conf.pri

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qbittorrent

.include <bsd.port.post.mk>
