# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/www/firefox-devel/Makefile,v 1.7 2008/08/07 04:42:35 mezz Exp $

PORTNAME=	firefox
DISTVERSION=	3.0.a2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/granparadiso/alpha2/source/
#MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}/source
DISTNAME=	granparadiso-alpha2-source
#DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nss>=3.11.2:${PORTSDIR}/security/nss

MOZILLA_NAME=	Firefox-${MOZILLA_SUFX}
MOZILLA_SUFX=	-devel
MOZILLA=	${PORTNAME}${MOZILLA_SUFX}
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/'
#MOZ_TOOLKIT=	cairo-gtk2

NO_LATEST_LINK=	yes

WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
EXTRA_CFLAGS=	-O2
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_PERL=	yes

FIREFOX_ICON=		${MOZILLA}.xpm
FIREFOX_ICON_SRC=	${PREFIX}/lib/firefox-devel/chrome/icons/default/default.xpm
MOZ_PKGCONFIG_FILES=	${MOZILLA}-js ${MOZILLA}-xpcom ${MOZILLA}-plugin
MOZ_OPTIONS=	--enable-application=browser \
		--enable-system-cairo	\
		--enable-official-branding \
		--enable-canvas	\
		--with-system-nss

SYSTEM_PREFS=		${FAKEDIR}/lib/${MOZILLA}/defaults/pref/firefox.js
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

OPTIONS=	NEWTAB "Open external links in a new tab" on \
		SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		Generic (unsupported) xpcom code was removed and will need to be \
		written or updated for !i386.
.endif

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 pthread | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

MOZ_OPTIONS+=	--disable-svg
#.if ${OSVERSION} >= 600000
# Needs MOZ_TOOLKIT=cairo-gtk2
#MOZ_OPTIONS+=	--enable-svg --enable-svg-renderer=cairo
#.endif

post-extract::
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor

port-pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLIST}
.if !defined(WITHOUT_NEWTAB)
	${ECHO_CMD} >> ${SYSTEM_PREFS}
	${ECHO_CMD} "// Open external links in new tab" >> ${SYSTEM_PREFS}
	${ECHO_CMD} "pref(\"browser.link.open_external\", 3);" \
		>> ${SYSTEM_PREFS}
.endif # !defined(WITHOUT_NEWTAB)

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include "${PORTSDIR}/www/mozilla/Makefile.common"
.include <bsd.port.post.mk>
