# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
DISTVERSION=	7.0.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.8.8:${PORTSDIR}/devel/nspr \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		event-1.4:${PORTSDIR}/devel/libevent

CONFLICTS_BUILD=	spidermonkey-*

USE_AUTOTOOLS=	autoconf213
USE_GECKO=	gecko
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-png -nss -dbm -jpeg -xft
MOZILLA_NAME=	Firefox
MOZ_TOOLKIT=	cairo-gtk2

MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
EXTRA_CFLAGS=	-O2
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		gl
NO_MOZPKGINSTALL=yes

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-svg --enable-svg-renderer=cairo \
		--enable-application=browser \
		--enable-official-branding --disable-updater \
		--enable-canvas --enable-libxul --disable-necko-wifi \
		--with-system-libevent=${LOCALBASE}

OPTIONS=	DBUS "Enable D-BUS support" on \
		PGO "Enable Profile-Guided Optimization" off

.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/mozilla-release

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
MOZ_OPTIONS+=	--enable-gnomeui
.else
MOZ_OPTIONS+=	--disable-gnomeui
.endif

.if defined(WITHOUT_DBUS)
MOZ_OPTIONS+=	--disable-dbus --disable-libnotify
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.4:${PORTSDIR}/devel/libnotify
.endif

.if defined(WITH_PGO)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
USE_PYTHON_BUILD=	yes
USE_DISPLAY=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"

MAKEFILE=	client.mk
ALL_TARGET=	profiledbuild
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif

pre-extract:
.if defined(WITH_PGO)
	@${ECHO} "*****************************************************************"
	@${ECHO} "**************************** attention **************************"
	@${ECHO} "*****************************************************************"
	@${ECHO} "To build Firefox with PGO support you need a running X server and"
	@${ECHO} "   build this port with an user who could access the X server!   "
	@${ECHO} ""
	@${ECHO} "During the build a Firefox instance will start and run some test."
	@${ECHO} "      Do not interrupt or close Firefox during this tests!       "
	@${ECHO} "*****************************************************************"
	@sleep 10
.endif

post-extract:
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	@${GREP} -Flr \"/proc ${WRKSRC}/ipc/chromium/src/base | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/proc/self/fd|/dev/fd|' \
		-e 's|/proc["/]|/compat/linux&|'
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/storage/build/Makefile.in \
		${WRKSRC}/toolkit/library/Makefile.in \
		${WRKSRC}/db/sqlite3/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in \
		${WRKSRC}/js/src/config/mkdepend/Makefile.in \
		${WRKSRC}/js/src/config/config.mk \
		${WRKSRC}/xpcom/io/nsAppFileLocationProvider.cpp
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/js/src/configure.in

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

post-configure:
.if defined(WITH_PGO)
	@${SED} -e 's|@PYTHON@|${PYTHON_CMD}|' \
		<${FILESDIR}/mozconfig-profile_guided_optimization.in \
		>> ${BUILD_WRKSRC}/.mozconfig
	(cd ${WRKSRC} && ${GMAKE} distclean)
.endif

port-pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLISTF}
	${ECHO_CMD} "@dirrmtry share/applications" >> ${PLISTD}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLISTF}

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
