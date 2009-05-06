# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flock
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/${PORTNAME}/releases/${PORTVERSION}/ \
		http://flock.vo.llnwd.net/o23/archive/${PORTNAME}/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg

USE_GECKO=	gecko
MOZILLA_NAME=	Flock
USE_MOZILLA=	-png -nss -dbm -jpeg
MOZ_TOOLKIT=	cairo-gtk2

WRKSRC?=	${WRKDIR}/source-svn-export-2.0/mozilla
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
EXTRA_CFLAGS=	-O2
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_PERL=	yes
GECKO_PLIST_PRE_FILES=	lib/${MOZILLA}/chrome/icons/default/default.xpm
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA} lib/${MOZILLA}/chrome \
			lib/${MOZILLA}/chrome/icons/default lib/${MOZILLA}/chrome/icons \
			lib/${MOZILLA}-devel-${DISTVERSION}/sdk/include \
			lib/${MOZILLA}-devel-${DISTVERSION}/sdk/idl \
			lib/${MOZILLA}-devel-${DISTVERSION}/lib \
			lib/${MOZILLA}-devel-${DISTVERSION}/bin \
			lib/${MOZILLA}-devel-${DISTVERSION}/include \
			lib/${MOZILLA}-devel-${DISTVERSION}/idl
MOZ_PKGCONFIG_FILES=
MAKE_JOBS_SAFE=	yes
NO_MOZPKGINSTALL=yes

FLOCK_ICON=	${MOZILLA}.xpm
FLOCK_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/icons/default.xpm
MOZ_OPTIONS=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-application=browser \
		--enable-system-cairo	\
		--enable-official-branding \
		--enable-canvas	\
		--enable-libxul \
		--with-clucene-prefix=${LOCALBASE} \
		--with-ffmpeg-prefix=${LOCALBASE}

SYSTEM_PREFS=		${FAKEDIR}/lib/${MOZILLA}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

OPTIONS=	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 pthread | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

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

.if ${ARCH} == "sparc64" && ${OSVERSION} < 601101
IGNORE=	does not run, update to 6.2-RELEASE or newer
.endif

MOZ_OPTIONS+=	--enable-svg --enable-svg-renderer=cairo

post-extract::
	@${SED} -e 's|@FLOCK_ICON@|${FLOCK_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/flock.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in \
		${WRKSRC}/db/sqlite3/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
	@${FIND} ${WRKSRC} -name all.js | ${XARGS} ${REINPLACE_CMD} -e \
		'/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/'

pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${FLOCK_ICON}' >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FLOCK_ICON_SRC} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default.xpm
	${LN} -sf ${FLOCK_ICON_SRC} ${PREFIX}/share/pixmaps/${FLOCK_ICON}

.include <bsd.port.post.mk>
