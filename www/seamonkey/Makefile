# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#    $MCom: ports-stable/www/seamonkey/Makefile,v 1.1 2006/03/09 21:26:46 ahze Exp $
#

PORTNAME=	seamonkey
DISTVERSION=	1.0.1
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	default
USE_X_PREFIX=	yes
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cairo"

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--enable-application=suite	\
		--enable-svg-renderer=cairo	\
		--enable-system-cairo		\
		--enable-canvas
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=suite

NOT_FOR_ARCHS=	ia64

OPTIONS=MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	JAVASCRIPT_DEBUGGER "Enable DTD and JavaScript debuggers" off \
	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/cairo/cairo-glitz.h)
# Glitz support can only be enabled if cairo is built with glitz support
MOZ_OPTIONS+=	--enable-glitz
LIB_DEPENDS+=	glitz.1:${PORTSDIR}/graphics/glitz
.endif

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035 || ${ARCH}=="sparc64"
IGNORE=		core dumps on ${ARCH} during post-build
.endif

.if ${OSVERSION} < 500000
BROKEN="Does not build"
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

.if defined(WITH_CALENDAR)
MOZ_OPTIONS+=	--enable-calendar
.endif

.if defined(WITHOUT_COMPOSER)
MOZ_OPTIONS+=	--disable-composer
.endif

post-patch:
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
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${ECHO_CMD} lib/browser_plugins/libjavaplugin_oji.so >> ${PLIST} ; \
				break; \
			fi; \
		done; \
	fi
	${ECHO_CMD} share/applications/seamonkey.desktop >> ${PLIST}
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
	${INSTALL_DATA} ${WRKDIR}/seamonkey.desktop ${PREFIX}/share/applications

.include "${.CURDIR}/../mozilla/Makefile.common"
.include <bsd.port.post.mk>
