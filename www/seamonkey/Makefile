# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		${MASTER_SITE_LOCAL:S,$,:local,}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION:S/M/m/}/src \
			sobomax/:local
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		libart_lgpl-${PORTVERSION}${EXTRACT_SUFX}:local

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
EXTRACT_AFTER_ARGS=	| tar -xf - -X ${FILESDIR}/tar-exclude
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GTK=	yes
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
		--enable-ldap			\
		--enable-mailnews		\
		--enable-mathml			\
		--disable-md			\
		--disable-optimize		\
		--disable-pedantic		\
		--disable-plaintext-editor-only	\
		--enable-reorder		\
		--enable-strip			\
		--enable-svg			\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-mng=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}	\
		--with-pthreads
.if !defined(WITHOUT_CHATZILLA)
CONFIGURE_ARGS+=	--with-extensions=default,irc
.endif
CONFIGURE_ENV=	MOZ_INTERNAL_LIBART_LGPL=1
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

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
	cd ${WRKSRC}/dist/bin && ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/lib/mozilla
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin

.include <bsd.port.mk>
