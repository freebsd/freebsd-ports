# New ports collection makefile for:	kismet
# Date created:			3 May 2004
# Whom:					Thomas Spreng <spreng@socket.ch>
#
# $FreeBSD$
#

PORTNAME=	kismet
PORTVERSION=	200805.r1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/
DISTNAME=	kismet-2008-05-R1

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	802.11 layer2 wireless network detector, sniffer, and IDS

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--enable-syspcap

OPTIONS=	CURSES "libcurses interface" on \
		PANEL "libpanels interface" on \
		SETUID "Install kismet with setuid" on \
		GPSMAP "Build gpsmap utility" off \
		GMAP "Build gpsmap with Google Maps patch *UNOFFICIAL*" off

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_CURSES)
CONFIGURE_ARGS+=--disable-curses
.endif

.ifdef(WITHOUT_PANEL)
CONFIGURE_ARGS+=--disable-panel
.endif

.ifdef(WITHOUT_SETUID)
CONFIGURE_ARGS+=--disable-setuid
.endif

.ifdef(WITH_GPSMAP)
PLIST_SUB+=	GPS=""
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		Magick++.2:${PORTSDIR}/graphics/ImageMagick
BUILD_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
MAN1=		gpsmap.1
.else
CONFIGURE_ARGS+=--disable-gpsmap
PLIST_SUB+=	GPS="@comment "
.endif

.ifdef(WITH_GMAP) && defined(WITH_GPSMAP)
PATCH_SITES=	http://www.parknation.com/gmap/files/
PATCHFILES=	gpsmap-gmap-0.1.tgz
PLIST_SUB+=	GMAP=""
.ifndef(NOPORTDOCS)
SUB_FILES+=	pkg-message
.endif
GMAP=		gpsmap-gmap
PORTDOCS=	${GMAP}/README.txt
.else
PLIST_SUB+=	GMAP="@comment "
.endif

MAN1+=		kismet.1 kismet_drone.1
MAN5=		kismet.conf.5 kismet_drone.conf.5 kismet_ui.conf.5

PORTDOCS+=	README

post-extract:
.ifdef(WITH_GMAP) && defined(WITH_GPSMAP)
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES}
	@${PATCH} -d ${WRKSRC}/${GMAP}-0.1 --forward --quiet < ${PKGDIR}/files/${GMAP}-0.1.diff.patch
	@${PATCH} -d ${WRKSRC} --forward --quiet < ${WRKSRC}/${GMAP}-0.1/${GMAP}-0.1.diff
.endif
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.ifdef(WITH_GMAP) && defined(WITH_GPSMAP)
	${MKDIR} ${DATADIR}/${GMAP}/mapfiles
	${INSTALL_DATA} ${WRKSRC}/${GMAP}-0.1/index.html ${DATADIR}/${GMAP}/index.html
	${INSTALL_DATA} ${WRKSRC}/${GMAP}-0.1/mapfiles/shadow.png ${DATADIR}/${GMAP}/mapfiles/shadow.png
	${INSTALL_DATA} ${WRKSRC}/${GMAP}-0.1/mapfiles/wep.png ${DATADIR}/${GMAP}/mapfiles/wep.png
	${INSTALL_DATA} ${WRKSRC}/${GMAP}-0.1/mapfiles/open.png ${DATADIR}/${GMAP}/mapfiles/open.png
	${INSTALL_DATA} ${WRKSRC}/${GMAP}-0.1/mapfiles/wpa.png ${DATADIR}/${GMAP}/mapfiles/wpa.png
.ifndef(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/${GMAP}-0.1/README.txt ${DOCSDIR}/${GMAP}
	@${CAT} ${PKGMESSAGE}
.endif
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/extra/manuf_update.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/conf/kismet.conf ${PREFIX}/etc/kismet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_drone.conf ${PREFIX}/etc/kismet_drone.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_ui.conf ${PREFIX}/etc/kismet_ui.conf.sample

.include <bsd.port.post.mk>
