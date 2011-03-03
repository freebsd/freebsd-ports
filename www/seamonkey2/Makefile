# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	seamonkey
DISTVERSION=	2.0.12
CATEGORIES?=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}/source
DISTNAME=	seamonkey-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

CONFLICTS_BUILD=	spidermonkey-1.[0-7]*
CONFLICTS_INSTALL=	seamonkey-1*
LATEST_LINK=	seamonkey2
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GECKO=	gecko
WANT_GNOME=	yes
WANT_PERL=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	default
MAKE_JOBS_SAFE=	yes
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE} CPPFLAGS="-I${LOCALBASE}/include/cairo" \
		ac_cv_func__Unwind_Backtrace=no
USE_GCC=	4.2+

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-svg \
		--enable-application=suite	\
		--enable-svg-renderer=cairo	\
		--enable-canvas
USE_MOZILLA=	-png -dbm -jpeg -xft -cairo
MOZ_TOOLKIT=	cairo-gtk2
MOZILLA_PLIST_DIRS=	bin lib
MOZ_PKGCONFIG_FILES=

NOT_FOR_ARCHS=	ia64

OPTIONS=MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	DBUS "Enable D-BUS support" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off \
	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
EXTRA_PATCHES=	${FILESDIR}/releng6_pulseaudio
.else
EXTRA_PATCHES=	${FILESDIR}/libsydney_oss
.endif

MOZSRC:=	${WRKDIR}/comm-1.9.1/mozilla
WRKSRC=		${WRKDIR}/comm-1.9.1

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 '%{\!pg: %{pthread:' | ${SED
} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

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
.else
MOZ_OPTIONS+=	--enable-ldap --enable-mailnews
.endif
.endif
.if !defined(WITHOUT_CHATZILLA)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif
.if defined(WITH_JAVASCRIPT_DEBUGGER)
MOZ_OPTIONS+=	--enable-jsd \
		--enable-dtd-debug
.else
MOZ_OPTIONS+=	--disable-jsd \
		--disable-dtd-debug
.endif

.if defined(WITHOUT_COMPOSER)
MOZ_OPTIONS+=	--disable-composer
.endif

.if defined(WITHOUT_DBUS)
MOZ_OPTIONS+=	--disable-dbus
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/mozilla/security/manager/ssl/src/Makefile.in \
		${WRKSRC}/mozilla/js/src/config/mkdepend/Makefile.in
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/mozilla/storage/build/Makefile.in
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/mozilla/modules/libpref/src/init/all.js
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
		${WRKSRC}/mozilla/js/src/configure \
		${WRKSRC}/mozilla/configure \
		${WRKSRC}/configure
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/seamonkey.desktop

port-pre-install:
	@${REINPLACE_CMD} -e 's|seamonkey-${PORTVERSION}|seamonkey|' \
		${FAKEDIR}/bin/seamonkey
	@${RM} -f ${FAKEDIR}/bin/seamonkey.bak
	${MV} ${FAKEDIR}/lib/seamonkey-${PORTVERSION} ${FAKEDIR}/lib/seamonkey

pre-install:
	${ECHO_CMD} share/applications/seamonkey.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/seamonkey.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
