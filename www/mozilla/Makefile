# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.0.1
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		http://people.FreeBSD.org/~marcus/:local
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION:S/.rc/rc/}/src \
		marcus/:local
DISTFILES=	${PORTNAME}-source-${PORTVERSION:S/.rc/rc/}${EXTRACT_SUFX} \
		libart_lgpl-${PORTVERSION}${EXTRACT_SUFX}:local

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

WITHOUT_CHATZILLA=	"Contains a buffer overflow reported at http://online.securityfocus.com/archive/1/270249"

USE_BZIP2=	yes
EXTRACT_AFTER_ARGS=	| tar -xf - -X ${FILESDIR}/tar-exclude
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	orbit gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=					\
		--disable-auto-deps		\
		--enable-chrome-format=jar	\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--enable-crypto			\
		--disable-debug			\
		--enable-default-toolkit=gtk	\
		--enable-double-buffer		\
		--enable-dtd-debug		\
		--enable-jsd			\
		--enable-mathml			\
		--disable-md			\
		--disable-optimize		\
		--disable-pedantic		\
		--disable-plaintext-editor-only	\
		--enable-strip			\
		--enable-svg			\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-mng=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}	\
		--with-pthreads

# LDAP is only used by mail and news so disable both together
.if defined(WITHOUT_MAILNEWS)
CONFIGURE_ARGS+=	--disable-ldap --disable-mailnews
PLIST_SUB+=	MOZILLAMAILNEWS="@comment "
PLIST_SUB+=	MOZILLALDAP="@comment "
.else
# mail and news desired, but not LDAP
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-ldap --enable-mailnews
PLIST_SUB+=	MOZILLAMAILNEWS=""
PLIST_SUB+=	MOZILLALDAP="@comment "
.else
CONFIGURE_ARGS+=	--enable-ldap --enable-mailnews
PLIST_SUB+=	MOZILLAMAILNEWS=""
PLIST_SUB+=	MOZILLALDAP=""
.endif 
.endif

.if !defined(WITHOUT_CHATZILLA)
CONFIGURE_ARGS+=	--enable-extensions=default,irc,xmlterm
PLIST_SUB+=	CHATZILLA=""
.else
CONFIGURE_ARGS+=	--enable-extensions=default,xmlterm
PLIST_SUB+=	CHATZILLA="@comment "
.endif
CONFIGURE_ENV=	MOZ_INTERNAL_LIBART_LGPL=1

.include <bsd.port.pre.mk>

MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

.if ${ARCH} == "alpha"
BROKEN=	"core dumps on alpha during post-build"
.endif

.if exists(${LOCALBASE}/include/freetype/freetype.h)
BROKEN="You must upgrade your freetype port to 1.3.1_2 or higher before installing Mozilla.  If you have 1.3.1_2 installed, please remove ${LOCALBASE}/include/freetype, then build Mozilla"
.endif

post-build:
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
		${FILESDIR}/mozilla.sh >${WRKSRC}/mozilla
	(cd ${WRKSRC}/dist/bin; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	  ${ECHO_CMD} skin,install,select,classic/1.0 >> chrome/installed-chrome.txt; \
	  ${ECHO_CMD} locale,install,select,en-US >> chrome/installed-chrome.txt; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	${FIND} ${WRKSRC}/dist/bin -type d | /usr/bin/sort -r | \
		${XARGS} ${RMDIR} 2> /dev/null || ${TRUE}

do-install:
	${MKDIR} ${PREFIX}/lib/mozilla
	${CHMOD} 755 ${PREFIX}/lib/mozilla
	cd ${WRKSRC}/dist/bin && ${FIND} . | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/mozilla
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin
	${LN} -sf ${LOCALBASE}/jdk1.3.1/jre/plugin/i386/ns600/libjavaplugin_oji.so \
		${PREFIX}/lib/mozilla/plugins/libjavaplugin_oji.so

.include <bsd.port.post.mk>
