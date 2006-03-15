# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#    $MCom: ports/www/mozilla/Makefile,v 1.36 2006/03/09 00:45:43 ahze Exp $
#

PORTNAME=	mozilla
PORTVERSION=	1.7.12
PORTREVISION?=	5
PORTEPOCH=	2
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION}/source \
			ahze/:local
DISTFILES=	${PORTNAME}-${PORTVERSION}-source${EXTRACT_SUFX} \
		libart_lgpl-1${EXTRACT_SUFX}:local

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
ALL_TARGET=	default

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MOZ_EXTENSIONS=	default
MOZ_EXPORT+=	MOZ_INTERNAL_LIBART_LGPL=1
MOZ_MK_OPTIONS+=MOZ_INTERNAL_LIBART_LGPL=1
MOZ_OPTIONS+=	--enable-svg-renderer-libart --enable-svg \
		--disable-plaintext-editor-only

NOT_FOR_ARCHS=	ia64

OPTIONS=CALENDAR "Enable the Calendar module" off \
	MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	XMLTERM "Enable the XMLTerm module" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off \
	SMB "Enable smb:// URI support using gnomevfs" off

.if !defined(WITHOUT_MAILNEWS)
GECKO_PLIST_PRE_FILES=	lib/${MOZILLA}/defaults/isp/US/movemail.rdf \
			lib/${MOZILLA}/defaults/isp/movemail.rdf
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/defaults/isp/US/ \
			lib/${MOZILLA}/defaults/isp
.endif

.include <bsd.port.pre.mk>

# libart patches
.if ${OSVERSION} < 500035
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-nsSVGLibartGlyphMetricsFT.cpp
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch2-nsSVGLibartGlyphMetricsFT.cpp
.endif

LATEST_LINK=	${MOZILLA}

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	core dumps on ${ARCH} during post-build
.endif

.if defined(WITH_CALENDAR) && (defined(WITHOUT_MAILNEWS) || \
	defined(WITHOUT_COMPOSER))
BROKEN=	Calendar requires Composer and Mailnews support.
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

.if !defined(WITHOUT_XMLTERM) && defined(WITH_JAVASCRIPT_DEBUGGER)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},xmlterm
.endif

.if defined(WITH_JAVASCRIPT_DEBUGGER)
MOZ_OPTIONS+=	--enable-jsd \
		--enable-dtd-debug
.else
MOZ_OPTIONS+=	--disable-jsd \
		--disable-dtd-debug
.endif

.if defined(WITH_CALENDAR)
MOZ_OPTIONS+=	--enable-calendar
.endif

.if defined(WITHOUT_COMPOSER)
MOZ_OPTIONS+=	--disable-composer
.endif

post-patch:
	@${FIND} ${WRKSRC}/other-licenses/libical -name "*.c" | ${XARGS} \
		${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/mozilla.desktop.in > \
		${WRKDIR}/mozilla.desktop

pre-install:
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${ECHO_CMD} lib/browser_plugins/libjavaplugin_oji.so >> ${PLIST} ; \
				break; \
			fi; \
		done; \
	fi
.if !defined(WITHOUT_MAILNEWS)
	@${CP} -RL ${WRKSRC}/dist/bin/defaults/isp ${FAKEDIR}/lib/${MOZILLA}/defaults
.endif
	${ECHO_CMD} share/applications/mozilla.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}

do-install:
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
		    		${LN} -sf $${jpi} \
			    		${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ; \
				break; \
			fi; \
		done; \
	fi
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/mozilla.desktop \
		${PREFIX}/share/applications

post-install:
	@${CHMOD} -R u-w ${PREFIX}/lib/${MOZILLA}/components

.include "${.CURDIR}/Makefile.common"
.include <bsd.port.post.mk>
