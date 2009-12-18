# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/www/firefox3/Makefile,v 1.20 2008/12/31 01:52:03 mezz Exp $
#

PORTNAME=	firefox
DISTVERSION=	3.0.16
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}-real/source
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.7:${PORTSDIR}/devel/nspr

LATEST_LINK=	firefox3
USE_GECKO=	gecko
CONFLICTS=	firefox-3.[1-6]*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-png -nss -dbm -jpeg
MOZILLA_NAME=	Firefox${MOZILLA_SUFX}
MOZILLA_SUFX=	3
MOZILLA=	${PORTNAME}${MOZILLA_SUFX}
MOZ_TOOLKIT=	cairo-gtk2
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/bin lib/${MOZILLA}/idl \
			lib/${MOZILLA}/include lib/${MOZILLA}/lib \
			lib/${MOZILLA}/sdk/idl lib/${MOZILLA}/sdk/include

WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
EXTRA_CFLAGS=	-O2
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
NO_MOZPKGINSTALL=yes

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-svg --enable-svg-renderer=cairo \
		--enable-application=browser \
		--enable-official-branding \
		--enable-canvas --enable-libxul

SYSTEM_PREFS=		${FAKEDIR}/lib/${MOZILLA}/defaults/pref/firefox.js

OPTIONS=	DBUS "Enable D-BUS support" on \
		NEWTAB "Open external links in a new tab" on \
		SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 '%{\!pg: %{pthread:' | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
MOZ_OPTIONS+=	--enable-gnomeui
.else
MOZ_OPTIONS+=	--disable-gnomeui
.endif

.if defined(WITHOUT_DBUS)
MOZ_OPTIONS+=	--disable-dbus
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.endif

post-extract::
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in \
		${WRKSRC}/db/sqlite3/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor
.if ${ARCH} == "sparc64"
	@(cd ${WRKSRC}/xpcom/reflect/xptcall/src/md/unix && \
	    ${LN} -s xptcstubs_asm_sparc64_openbsd.s xptcstubs_asm_sparc64_freebsd.s && \
	    ${LN} -s xptcstubs_sparc64_openbsd.cpp xptcstubs_sparc64_freebsd.cpp && \
	    ${LN} -s xptcinvoke_sparc64_openbsd.cpp xptcinvoke_sparc64_freebsd.cpp && \
	    ${LN} -s xptcinvoke_asm_sparc64_openbsd.s xptcinvoke_asm_sparc64_freebsd.s)
.endif

port-pre-install:
#	${SED} -e 's|1.9a7|0|' ${WRKSRC}/dist/bin/application.ini ${FAKEDIR}/lib
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLISTF}
	${ECHO_CMD} "@dirrmtry share/applications" >> ${PLISTD}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLISTF}
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

.include <bsd.port.post.mk>
