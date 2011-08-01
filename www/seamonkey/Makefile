# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	seamonkey
DISTVERSION=	2.2
CATEGORIES?=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}/source
DISTNAME=	seamonkey-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=  nspr>=4.8.7:${PORTSDIR}/devel/nspr
LIB_DEPENDS=    execinfo.1:${PORTSDIR}/devel/libexecinfo \
                event-1.4:${PORTSDIR}/devel/libevent

USE_AUTOTOOLS=	autoconf213
CONFLICTS_BUILD=	spidermonkey-1.[0-7]*
CONFLICTS_INSTALL=	seamonkey-2.0*
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GECKO=	gecko
WANT_GNOME=	yes
WANT_PERL=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	default
USE_GL=		gl
MAKE_JOBS_SAFE=	yes
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cairo"
USE_GCC=	4.2+

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MOZILLA=	${PORTNAME}-${PORTVERSION}
MOZILLA_EXEC_NAME=	${PORTNAME}
MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-svg \
		--enable-application=suite	\
		--enable-svg-renderer=cairo	\
		--enable-system-cairo		\
		--enable-canvas			\
		--disable-necko-wifi		\
		--disable-updater		\
		--with-system-libevent=${LOCALBASE}

USE_MOZILLA=	-png -nss -dbm -jpeg -xft
MOZ_TOOLKIT=	cairo-gtk2
MOZILLA_PLIST_DIRS=	bin lib
MOZ_PKGCONFIG_FILES=

NOT_FOR_ARCHS=	ia64

OPTIONS=MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	LIGHTNING "Enable calendar extension" off \
	DBUS "Enable D-BUS support" on \
	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

MOZSRC:=	${WRKDIR}/comm-release/mozilla
WRKSRC=		${WRKDIR}/comm-release

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 '%{\!pg: %{pthread:' | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
MOZ_OPTIONS+=	--enable-gnomeui
.else
MOZ_OPTIONS+=	--disable-gnomeui
.endif

.if exists(${LOCALBASE}/include/cairo/cairo-glitz.h)
# Glitz support can only be enabled if cairo is built with glitz support
MOZ_OPTIONS+=	--enable-glitz
LIB_DEPENDS+=	glitz.1:${PORTSDIR}/graphics/glitz
.endif

.if defined(WITHOUT_MAILNEWS)
MOZ_OPTIONS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if defined(WITHOUT_LDAP)
MOZ_OPTIONS+=	--disable-ldap --enable-mailnews
BROKEN=		Does not build
.else
MOZ_OPTIONS+=	--enable-ldap --enable-mailnews
.endif
.endif
.if !defined(WITHOUT_CHATZILLA)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif

.if defined(WITHOUT_COMPOSER)
MOZ_OPTIONS+=	--disable-composer
.endif

.if defined(WITHOUT_DBUS)
MOZ_OPTIONS+=	--disable-dbus --disable-libnotify
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.1:${PORTSDIR}/devel/libnotify
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif

.if defined(WITH_LIGHTNING)
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/mozilla/security/manager/ssl/src/Makefile.in \
		${WRKSRC}/mozilla/js/src/config/mkdepend/Makefile.in
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${MOZSRC}/storage/build/Makefile.in \
		${MOZSRC}/toolkit/library/Makefile.in \
		${MOZSRC}/db/sqlite3/src/Makefile.in
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/mozilla/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure.in \
		${WRKSRC}/mozilla/configure.in \
		${WRKSRC}/mozilla/xpcom/io/nsNativeCharsetUtils.cpp
	@${REINPLACE_CMD} -e 's|libgnome-2.so.0|libgnome-2.so|' \
		${WRKSRC}/mozilla/toolkit/xre/nsNativeAppSupportUnix.cpp \
		${WRKSRC}/mozilla/modules/libpr0n/decoders/icon/gtk/nsIconChannel.cpp
	@${REINPLACE_CMD} -e 's|libgnomeui-2.so.0|libgnomeui-2.so|' \
		${WRKSRC}/mozilla/toolkit/xre/nsNativeAppSupportUnix.cpp \
		${WRKSRC}/mozilla/modules/libpr0n/decoders/icon/gtk/nsIconChannel.cpp
	@${REINPLACE_CMD} -e 's|libgnomevfs-2.so.0|libgnomevfs-2.so|' \
		${WRKSRC}/mozilla/modules/libpr0n/decoders/icon/gtk/nsIconChannel.cpp
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/mozilla/js/src/configure.in \
		${WRKSRC}/mozilla/configure.in \
		${WRKSRC}/configure.in
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/seamonkey.desktop
pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

pre-install:
	${ECHO_CMD} share/applications/seamonkey.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
.if defined(WITH_LIGHTNING)
	@${PRINTF} '%s/lightning-${PORTNAME}.xpi\n@dirrmtry %s\n' \
		${LIGHTNING_DIR} ${LIGHTNING_DIR} >> ${PLIST}
.endif

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/seamonkey.desktop ${PREFIX}/share/applications

post-install:
.if defined(WITH_LIGHTNING)
	${MKDIR} ${PREFIX}/${LIGHTNING_DIR}
	${INSTALL_DATA} ${MOZSRC}/dist/xpi-stage/lightning.xpi ${PREFIX}/${LIGHTNING_DIR}/lightning-${PORTNAME}.xpi
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
