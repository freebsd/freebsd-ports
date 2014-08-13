# Created by: Kris Kennaway <kkennawa@physics.adelaide.edu.au>
# $FreeBSD: head/multimedia/linux-realplayer/Makefile 357525 2014-06-11 18:54:20Z riggs $

PORTNAME=	linux-realplayer
DISTVERSION=	10.0.9.809-20070726
PORTREVISION=	5
CATEGORIES=	multimedia audio linux
MASTER_SITES=	ftp://ftp.tw.freebsd.org/pub/distfiles/:player \
		http://freeheimdall.spdns.org/files/:player \
		http://freeheimdall.spdns.org/files/:codecs \
		http://mirror.therek.net/freebsd/distfiles/mplayer/:codecs \
		SF/mplayer-tru/mplayer-codecs/20040704:codecs \
		ftp://fr2.rpmfind.net/linux/sourceforge/m/mp/mplayer-tru/mplayer-codecs/20040704/:codecs \

DISTFILES=	RealPlayer10GOLD.rpm:player \
		mplayer-codecs-linux-real-20040626-1.i386.rpm:codecs

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Linux RealPlayer 10 from RealNetworks

LICENSE=	RealPlayer
LICENSE_NAME=	Helix DNA Technology Binary Research Use License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/usr/local/RealPlayer
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	gtk2 xorglibs
RESTRICTED=	Redistribution not allowed
NO_BUILD=	yes
WANT_GNOME=	yes

RADIR=		${PREFIX}/lib/RealPlayer
PLUGINSDIR=	${PREFIX}/lib/linux-mozilla/plugins
RABINDIR=	${PREFIX}/bin

OPTIONS_DEFINE=	GNOME ICONS NLS
OPTIONS_DEFAULT=	ICONS

ICONS_DESC=	Install set of icons

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS="" LINUXBASE="${LINUXBASE}"
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MICONS}
PLIST_SUB+=	ICONS=""
.else
PLIST_SUB+=	ICONS="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gnomehier
USES+=		desktop-file-utils
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.if ${PORT_OPTIONS:MICONS} || ${PORT_OPTIONS:MGNOME}
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@for f in ${_DISTFILES}; do\
		cd ${WRKDIR}; ${TAR} -xf ${DISTDIR}/$$f ; \
	done

post-patch:
	@${SED} 's|/usr/local|${PREFIX}|' \
		< ${FILESDIR}/realplay > ${WRKSRC}/realplay

do-install:
	@${MKDIR} ${STAGEDIR}${RADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${RADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/realplay.bin ${STAGEDIR}${RADIR}
	${BRANDELF} -t Linux ${STAGEDIR}${RADIR}/realplay.bin
.for dir in codecs common lib plugins share/default share/realplay
	@${MKDIR} ${STAGEDIR}${RADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${STAGEDIR}${RADIR}/${dir}
.endfor

# Extra codecs from the RealPlayer-9 -- no longer shipped by Real,
# but still in use by major content providers, such as Amazon:
.for c in dnet ddnt
	${INSTALL_DATA} ${WRKDIR}/usr/lib/codecs/$c.so.6.0 \
		${STAGEDIR}${RADIR}/codecs/
	${LN} -sf $c.so.6.0 ${STAGEDIR}${RADIR}/codecs/$c.so
.endfor

.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${STAGEDIR}${RADIR}/share/locale
	${CP} -Rp ${WRKSRC}/share/locale/* ${STAGEDIR}${RADIR}/share/locale
.for c in de es fr hi it ja ko pl pt_BR zh_CN zh_TW
	@${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/share/locale/${c}/LC_MESSAGES
	${INSTALL_DATA} ${STAGEDIR}${RADIR}/share/locale/${c}/player.mo \
		${STAGEDIR}${LINUXBASE}/usr/share/locale/${c}/LC_MESSAGES/realplay.mo
.endfor
.endif

	@${MKDIR} ${STAGEDIR}${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/mozilla/* ${STAGEDIR}${PLUGINSDIR}

	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/realplay ${STAGEDIR}${PREFIX}/bin

.if ${PORT_OPTIONS:MICONS}
. for size in 16x16 32x32 48x48 192x192
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKSRC}/share/icons/realplay_${size}.png \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}/apps
. endfor
. for size in 48x48 192x192
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}/mimetypes
	${INSTALL_DATA} ${WRKSRC}/share/icons/mime-*_${size}.png \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}/mimetypes
. endfor
.endif

.if ${PORT_OPTIONS:MGNOME}
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/share/realplay.png \
		${STAGEDIR}${LOCALBASE}/share/pixmaps

	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/realplay.desktop \
		${STAGEDIR}${LOCALBASE}/share/applications

	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/application-registry
	${INSTALL_DATA} ${WRKSRC}/share/realplay.applications \
		${STAGEDIR}${LOCALBASE}/share/application-registry

	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/mime-info
	${INSTALL_DATA} ${WRKSRC}/share/realplay.keys ${WRKSRC}/share/realplay.mime \
		${STAGEDIR}${LOCALBASE}/share/mime-info
.endif

.include <bsd.port.post.mk>
