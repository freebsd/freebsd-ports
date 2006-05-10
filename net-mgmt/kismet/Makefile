# New ports collection makefile for:	kismet
# Date created:			3 May 2004
# Whom:					Thomas Spreng <spreng@socket.ch>
#
# $FreeBSD$
#

PORTNAME=	kismet
PORTVERSION=	200508.r1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/
DISTNAME=	kismet-2005-08-R1

MAINTAINER=	eol1@yahoo.com
COMMENT=	802.11 layer2 wireless network detector, sniffer, and IDS

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--enable-syspcap

OPTIONS=	CURSES "libcurses interface" on \
		PANEL "libpanels interface" on \
		SETUID "Install kismet with setuid" on \
		GPSMAP "Build gpsmap utility" on \
		GMAP "Build gpsmap with Google Maps patch *UNOFFICIAL*" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CURSES)
CONFIGURE_ARGS+=--disable-curses
.endif

.if defined(WITHOUT_PANEL)
CONFIGURE_ARGS+=--disable-panel
.endif

.if defined(WITHOUT_SETUID)
CONFIGURE_ARGS+=--disable-setuid
.endif

.if defined(WITHOUT_GPSMAP)
CONFIGURE_ARGS+=--disable-gpsmap
PLIST_SUB+=	GPS="@comment "
.else
PLIST_SUB+=	GPS=""
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		Magick++.9:${PORTSDIR}/graphics/ImageMagick
BUILD_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
RUN_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
.endif

.if defined(WITH_GMAP) && !defined(WITHOUT_GPSMAP)
PATCH_SITES=	http://www.parknation.com/gmap/files/
PATCHFILES=	gpsmap-gmap-0.1.tgz
PLIST_SUB+=	GMAP=""
SUB_FILES=	pkg-message
.else
PLIST_SUB+=	GMAP="@comment "
.endif

MAN1=		kismet.1 kismet_drone.1 gpsmap.1
MAN5=		kismet.conf.5 kismet_drone.conf.5 kismet_ui.conf.5

.if ${OSVERSION} < 502000
CONFIGURE_ARGS+=	--disable-pcap
.endif

post-extract:
.if defined(WITH_GMAP) && !defined(WITHOUT_GPSMAP)
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} 
	@${PATCH} -d ${WRKSRC}/gpsmap-gmap-0.1 --forward --quiet < ${PKGDIR}/files/gpsmap-gmap-0.1.diff.patch
	@${PATCH} -d ${WRKSRC} --forward --quiet < ${WRKSRC}/gpsmap-gmap-0.1/gpsmap-gmap-0.1.diff
.endif
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-install:
.if defined(WITH_GMAP) && !defined(WITHOUT_GPSMAP)
	${MKDIR} ${PREFIX}/share/${PORTNAME}/gpsmap-gmap
	${MKDIR} ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/mapfiles
	${INSTALL_DATA} ${WRKSRC}/gpsmap-gmap-0.1/index.html ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/index.html
	${INSTALL_DATA} ${WRKSRC}/gpsmap-gmap-0.1/README.txt ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/README.txt
	${INSTALL_DATA} ${WRKSRC}/gpsmap-gmap-0.1/mapfiles/shadow.png ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/mapfiles/shadow.png
	${INSTALL_DATA} ${WRKSRC}/gpsmap-gmap-0.1/mapfiles/wep.png ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/mapfiles/wep.png
	${INSTALL_DATA} ${WRKSRC}/gpsmap-gmap-0.1/mapfiles/open.png ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/mapfiles/open.png
	${INSTALL_DATA} ${WRKSRC}/gpsmap-gmap-0.1/mapfiles/wpa.png ${PREFIX}/share/${PORTNAME}/gpsmap-gmap/mapfiles/wpa.png
	@${CAT} ${PKGMESSAGE}
.endif
	${INSTALL_DATA} ${WRKSRC}/conf/kismet.conf ${PREFIX}/etc/kismet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_drone.conf ${PREFIX}/etc/kismet_drone.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_ui.conf ${PREFIX}/etc/kismet_ui.conf.sample

.include <bsd.port.post.mk>
