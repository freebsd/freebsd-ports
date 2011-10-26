# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	seamonkey
DISTVERSION=	2.4.1
CATEGORIES?=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}/source
DISTNAME=	seamonkey-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	nspr>=4.8.7:${PORTSDIR}/devel/nspr
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		event-1.4:${PORTSDIR}/devel/libevent

USE_AUTOTOOLS=	autoconf213
CONFLICTS_BUILD=	spidermonkey-1.[0-7]*
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
CPPFLAGS+=	-I${LOCALBASE}/include/cairo
USE_GCC=	4.2+

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--program-transform-name='s/seamonkey/${MOZILLA}/' \
		--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
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
EXTRA_PATCHES+=	${FILESDIR}/extra-mailnews-patch-bridge-bridge.mk
MOZ_OPTIONS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if defined(WITHOUT_LDAP)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bridge-bridge.mk
MOZ_OPTIONS+=	--disable-ldap --enable-mailnews
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
		notify.4:${PORTSDIR}/devel/libnotify
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif

.if defined(WITH_LIGHTNING)
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
XPI_FILE=	${MOZSRC}/dist/xpi-stage/lightning.xpi
XPI_LIBDIR=	${PREFIX}/lib/xpi
XPI_ORIG_ID=	{e2fda1a4-762b-4020-b5ad-a41df1933103}
XPI_ID=		lightning@seamonkey.mozilla.org
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/mozilla/security/manager/ssl/src/Makefile.in \
		${WRKSRC}/mozilla/js/src/config/mkdepend/Makefile.in
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
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
	@${SED} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/${MOZILLA}.desktop
pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

pre-install:
	${ECHO_CMD} share/applications/${MOZILLA}.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${MOZILLA}.png' >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${LN} -sf ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png \
		${PREFIX}/share/pixmaps/${MOZILLA}.png

post-install:
.if defined(WITH_LIGHTNING)
	@${MKDIR} ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/seamonkey
	@(cd ${XPI_LIBDIR}/${XPI_ID}; ${TAR} -xf ${XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${XPI_ID}
	@${REINPLACE_CMD} -i "" "s/${XPI_ORIG_ID}/${XPI_ID}/" ${XPI_LIBDIR}/${XPI_ID}/install.rdf
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${XPI_ID}
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${LOCALBASE}/lib/seamonkey/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/seamonkey 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/seamonkey/${XPI_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${XPI_ID} ${LOCALBASE}/lib/seamonkey/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/seamonkey/extensions/${XPI_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks/seamonkey 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi 2>/dev/null || true' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
