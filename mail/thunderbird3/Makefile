# New ports collection makefile for:    mozilla-thunderbird
# Date created:         4 September 2003
# Whom:             Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thunderbird
DISTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}/source/
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

BUILD_DEPENDS=	nspr>=4.8:${PORTSDIR}/devel/nspr

USE_AUTOTOOLS=	autoconf:213
LATEST_LINK=	thunderbird3
USE_GECKO=	gecko
CONFLICTS=	thunderbird-2* lightning-0.[0-9]*
USE_MOZILLA=	-png -nss -dbm -jpeg -xft
MOZ_TOOLKIT=	cairo-gtk2

MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
MAKE_ENV=	PTHREAD_LDFLAGS="${PTHREAD_LIBS}"
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

MOZILLA=	${PORTNAME}-${PORTVERSION}
MOZILLA_EXEC_NAME=	${PORTNAME}
MOZ_PROTOCOLS=	http,ftp,file,viewsource,res,data
MOZ_GRAPHICS=	default,-xbm
MOZ_OPTIONS=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
	--enable-single-profile --disable-profilesharing \
	--enable-application=mail --enable-official-branding
MOZ_MK_OPTIONS=	MOZ_MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZ_EXPORT=		MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZILLA_PLIST_DIRS=	bin lib
MOZ_PKGCONFIG_FILES=

PORTNAME_ICON=	${PORTNAME}.png
PORTNAME_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=moz_pis_S50cleanhome

OPTIONS=

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/comm-1.9.1
MOZSRC:=	${WRKSRC}/mozilla

.if ${OSVERSION} < 700000
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
EXTRA_PATCHES=	${FILESDIR}/releng6_pulseaudio
.else
EXTRA_PATCHES=	${FILESDIR}/liboggplay_oss
.endif

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
	${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON}|' \
		<${FILESDIR}/thunderbird.desktop.in >${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop
	${LN} -s  ${WRKSRC}/mail ${WRKSRC}/mozilla/mail

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${MOZSRC}/storage/build/Makefile.in \
		${MOZSRC}/db/sqlite3/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${MOZSRC}/security/manager/ssl/src/Makefile.in \
		${MOZSRC}/js/src/config/mkdepend/Makefile.in \
		${MOZSRC}/js/src/config/config.mk
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${MOZSRC}/js/src/configure

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

port-pre-install:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	${FAKEDIR}/bin/thunderbird
	${RM} -f ${FAKEDIR}/bin/*.bak
	${MKDIR} ${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults

pre-install:
	@${ECHO_CMD} 'share/applications/${PORTNAME}.desktop' >> ${PLIST}
	@${ECHO_CMD} 'share/pixmaps/${PORTNAME_ICON}' >> ${PLIST}
	@${ECHO_CMD} '@dirrmtry share/applications' >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${PREFIX}/share/applications
	${LN} -sf ${PORTNAME_ICON_SRC} ${PREFIX}/share/pixmaps/${PORTNAME_ICON}

.include <bsd.port.post.mk>
