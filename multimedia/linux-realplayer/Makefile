# New ports collection makefile for:   linux-realplayer
# Date created:        31 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	linux-realplayer
DISTVERSION=	10.0.8.805-20060718
CATEGORIES=	multimedia audio linux
MASTER_SITES=	https://helixcommunity.org/download.php/2152/:player \
		http://ftp.nluug.nl/ftp/pub/os/Linux/distr/pardusrepo/sources/:playeralt \
		ftp://fr2.rpmfind.net/linux/sourceforge/m/mp/mplayer-tru/:codecs
DISTFILES=	RealPlayer-${DISTVERSION}.i586.rpm:player,playeralt \
		mplayer-codecs-linux-real-20040626-1.i386.rpm:codecs

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Linux RealPlayer 10 from RealNetworks

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2

WRKSRC=		${WRKDIR}/usr/local/RealPlayer
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_X_PREFIX=	yes
RESTRICTED=	Redistribution not allowed
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

.if exists(${LOCALBASE}/share/icons)
WITH_ICONS=	yes
PLIST_SUB+=	ICONS=""
.else
PLIST_SUB+=	ICONS="@comment "
.endif

.if exists(${LOCALBASE}/share/gnome)
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
	@set -x; for f in ${_DISTFILES}; do\
		cd ${WRKDIR}; rpm2cpio.pl ${DISTDIR}/$$f | \
		    ${CPIO} -idm --quiet; \
	done

post-patch:
	@${SED} 's|/usr/local|${PREFIX}|' \
		< ${FILESDIR}/realplay > ${WRKSRC}/realplay

do-install:
	@${MKDIR} ${RADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${RADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/realplay.bin ${RADIR}
	${BRANDELF} -t Linux ${RADIR}/realplay.bin
.for dir in codecs common lib plugins share/default share/realplay
	@${MKDIR} ${RADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${RADIR}/${dir}
.endfor

# Extra codecs from the RealPlayer-9 -- no longer shipped by Real,
# but still in use by major content providers, such as Amazon:
.for c in dnet ddnt
	${INSTALL_DATA} ${WRKDIR}/usr/lib/codecs/$c.so.6.0	\
		${RADIR}/codecs/
	${LN} -s $c.so.6.0 ${RADIR}/codecs/$c.so
.endfor

.if !defined(WITHOUT_NLS)
	@${MKDIR} ${RADIR}/share/locale
	${CP} -Rp ${WRKSRC}/share/locale/* ${RADIR}/share/locale
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RADIR}/share/locale
.endif

	@${MKDIR} ${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/mozilla/* ${PLUGINSDIR}

	@${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/realplay ${PREFIX}/bin

.if defined(WITH_ICONS)
. for size in 16x16 32x32 48x48 192x192
	@${MKDIR} ${LOCALBASE}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKSRC}/share/icons/realplay_${size}.png \
		${LOCALBASE}/share/icons/hicolor/${size}/apps
. endfor
. for size in 48x48 192x192
	@${MKDIR} ${LOCALBASE}/share/icons/hicolor/${size}/mimetypes
	${INSTALL_DATA} ${WRKSRC}/share/icons/mime-*_${size}.png \
		${LOCALBASE}/share/icons/hicolor/${size}/mimetypes
. endfor
.endif

.if defined(WITH_GNOME)
	@${MKDIR} ${LOCALBASE}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/share/realplay.png \
		${LOCALBASE}/share/gnome/pixmaps

	@${MKDIR} ${LOCALBASE}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/share/realplay.desktop \
		${LOCALBASE}/share/gnome/applications

	@${MKDIR} ${LOCALBASE}/share/gnome/application-registry
	${INSTALL_DATA} ${WRKSRC}/share/realplay.applications \
		${LOCALBASE}/share/gnome/application-registry

	@${MKDIR} ${LOCALBASE}/share/gnome/mime-info
	${INSTALL_DATA} ${WRKSRC}/share/realplay.keys ${WRKSRC}/share/realplay.mime \
		${LOCALBASE}/share/gnome/mime-info
.endif

.include <bsd.port.post.mk>
