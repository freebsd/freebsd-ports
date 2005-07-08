# New ports collection makefile for:   linux-realplayer
# Date created:        31 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	linux-realplayer
PORTVERSION=	10.0.5
CATEGORIES=	multimedia audio linux
MASTER_SITES=	https://helixcommunity.org/download.php/1343/
DISTNAME=	RealPlayer-10.0.5.756-20050513.i586
EXTRACT_SUFX=	.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux RealPlayer 10 from RealNetworks

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	\
	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2

WRKSRC=		${WRKDIR}/usr/local/RealPlayer
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_X_PREFIX=	yes
RESTRICTED=	"Redistribution not allowed"
NO_BUILD=	yes

RADIR=		${PREFIX}/lib/RealPlayer
PLUGINSDIR=	${PREFIX}/lib/linux-mozilla/plugins
RABINDIR=	${PREFIX}/bin

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/share/icons)
WITH_ICONS=	yes
PLIST_SUB+=	ICONS=""
.else
PLIST_SUB+=	ICONS="@comment "
.endif

.if exists(${X11BASE}/share/gnome)
WITH_GNOME=	yes
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.if defined(WITH_ICONS) || defined(WITH_GNOME)
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	cd ${WRKDIR}; rpm2cpio.pl ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${CPIO} -id --quiet

post-patch:
	@${SED} 's|/usr/local|${PREFIX}|' \
		< ${FILESDIR}/realplay > ${WRKSRC}/realplay

do-install:
	${MKDIR} ${RADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${RADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/realplay.bin ${RADIR}
	${BRANDELF} -t Linux ${RADIR}/realplay.bin

.for dir in codecs common lib plugins share/default share/realplay
	${MKDIR} ${RADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${RADIR}/${dir}
.endfor

.if !defined(WITHOUT_NLS)
	${MKDIR} ${RADIR}/share/locale
	${CP} -R ${WRKSRC}/share/locale/* ${RADIR}/share/locale
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RADIR}/share/locale
.endif

	${MKDIR} ${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/mozilla/* ${PLUGINSDIR}

	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/realplay ${PREFIX}/bin

.if defined(WITH_ICONS)
. for size in 16x16 32x32 48x48 192x192
	${MKDIR} ${X11BASE}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKSRC}/share/icons/realplay_${size}.png \
		${X11BASE}/share/icons/hicolor/${size}/apps
. endfor
. for size in 48x48 192x192
	${MKDIR} ${X11BASE}/share/icons/hicolor/${size}/mimetypes
	${INSTALL_DATA} ${WRKSRC}/share/icons/mime-*_${size}.png \
		${X11BASE}/share/icons/hicolor/${size}/mimetypes
. endfor
.endif

.if defined(WITH_GNOME)
	${MKDIR} ${X11BASE}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/share/realplay.png ${X11BASE}/share/gnome/pixmaps

	${MKDIR} ${X11BASE}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/share/realplay.desktop \
		${X11BASE}/share/gnome/applications

	${MKDIR} ${X11BASE}/share/gnome/application-registry
	${INSTALL_DATA} ${WRKSRC}/share/realplay.applications \
		${X11BASE}/share/gnome/application-registry

	${MKDIR} ${X11BASE}/share/gnome/mime-info
	${INSTALL_DATA} ${WRKSRC}/share/realplay.keys ${WRKSRC}/share/realplay.mime \
		${X11BASE}/share/gnome/mime-info
.endif

.include <bsd.port.post.mk>
