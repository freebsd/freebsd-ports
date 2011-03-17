# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#   $MCom: ports-stable/www/seamonkey/Makefile,v 1.9 2009/01/09 23:41:22 mezz Exp $
#

PORTNAME=	seamonkey
DISTVERSION=	1.1.19
PORTREVISION=	1
CATEGORIES?=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

DEPRECATED=	Upstream support dropped. Please consider using www/seamonkey2 instead.
FORBIDDEN=	several security vulnerabilities
CONFLICTS=	seamonkey-2*
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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cairo"

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

GECKO_PLIST_PRE_FILES=	lib/${MOZILLA}/chrome/icons/default/default.xpm

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-svg \
		--enable-application=suite	\
		--enable-svg-renderer=cairo	\
		--enable-system-cairo		\
		--enable-canvas \
		--with-system-nss
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=suite

NOT_FOR_ARCHS=	ia64

OPTIONS=MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off \
	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 pthread | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if exists(${LOCALBASE}/include/cairo/cairo-glitz.h)
# Glitz support can only be enabled if cairo is built with glitz support
MOZ_OPTIONS+=	--enable-glitz
LIB_DEPENDS+=	glitz.1:${PORTSDIR}/graphics/glitz
.endif

.if ${ARCH}=="sparc64" && ${OSVERSION} < 601101
IGNORE=		core dumps on ${ARCH}, need kern.osreldate>=601101
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
MOZ_OPTIONS+=		--enable-jsd \
			--enable-dtd-debug
.else
MOZ_OPTIONS+=		--disable-jsd \
			--disable-dtd-debug
.endif

.if defined(WITHOUT_COMPOSER)
MOZ_OPTIONS+=	--disable-composer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/seamonkey.desktop

pre-install:
	${ECHO_CMD} share/applications/seamonkey.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${CP} ${WRKSRC}/suite/branding/icons/gtk/default.xpm \
		${FAKEDIR}/lib/${MOZILLA}/chrome/icons/default/

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/seamonkey.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
