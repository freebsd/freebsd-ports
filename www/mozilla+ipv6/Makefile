# New ports collection makefile for:	mozilla+ipv6
# Date created:		25 Aug 2000
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9.7
PORTREVISION=	2
PORTEPOCH=	1
PKGNAMESUFFIX=	+ipv6
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL:S,%SUBDIR%,sobomax,} \
		${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION:S/M/m/}/src
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		libart_lgpl-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sumikawa@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=					\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--disable-debug			\
		--disable-idltool		\
		--disable-md			\
		--disable-pedantic		\
		--disable-xterm-updates		\
		--enable-crypto			\
		--enable-double-buffer		\
		--enable-editor			\
		--enable-mailnews		\
		--enable-mathml			\
		--enable-optimize="${CFLAGS}"	\
		--enable-pics			\
		--enable-svg			\
		--enable-tests			\
		--enable-toolkit=gtk		\
		--enable-x11-shm		\
		--enable-chrome-format=jar	\
		--with-jpeg=${LOCALBASE}	\
		--with-png=${LOCALBASE}		\
		--with-mng=${LOCALBASE}		\
		--with-pthreads
.if !defined(WITHOUT_CHATZILLA)
CONFIGURE_ARGS+=	--with-extensions=default,irc
.endif
CONFIGURE_ENV=	BSD_PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CFLAGS="" CXXFLAGS="" \
		MOZ_INTERNAL_LIBART_LGPL=1
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		CFLAGS="" CXXFLAGS="" \
		MALLOC_OPTIONS=j \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

post-build:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" \
		${FILESDIR}/mozilla.sh >${WRKSRC}/mozilla
	@(cd ${WRKSRC}/dist/bin; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	  ${ECHO} skin,install,select,classic/1.0 >> chrome/installed-chrome.txt; \
	  ${ECHO} locale,install,select,en-US >> chrome/installed-chrome.txt; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@/usr/bin/find ${WRKSRC}/dist/bin -type d | /usr/bin/sort -r | \
		/usr/bin/xargs ${RMDIR} 2> /dev/null || ${TRUE}

do-install:
	${MKDIR} ${PREFIX}/lib/mozilla
	${CHMOD} 755 ${PREFIX}/lib/mozilla
	cd ${WRKSRC}/dist/bin && ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/lib/mozilla
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin

.include <bsd.port.mk>
