# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION:S/M/m/}/src
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	reg@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng

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
		--enable-double-buffer		\
		--enable-editor			\
		--enable-mailnews		\
		--enable-mathml			\
		--enable-optimize		\
		--enable-pics			\
		--enable-svg			\
		--enable-tests			\
		--enable-toolkit=gtk		\
		--enable-x11-shm		\
		--enable-chrome-format=both	\
		--with-jpeg=${LOCALBASE}	\
		--with-png=${LOCALBASE}		\
		--with-mng=${LOCALBASE}		\
		--with-pthreads
CONFIGURE_ENV=	BSD_PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} BUILD_MODULES=psm
	@${SED} -e "s;@PREFIX@;${PREFIX};g" \
		${FILESDIR}/mozilla.sh >${WRKSRC}/mozilla
	@${CHMOD} 555 ${WRKSRC}/mozilla
	@(cd ${WRKSRC}/dist/bin; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	  ${ECHO} skin,install,select,classic/1.0 >> chrome/installed-chrome.txt; \
	  ${ECHO} locale,install,select,en-US >> chrome/installed-chrome.txt; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)

do-install:
	${MKDIR} ${PREFIX}/lib/mozilla
	${CHMOD} 755 ${PREFIX}/lib/mozilla
	cd ${WRKSRC}/dist/bin && ${TAR} --exclude "*.jar" -chf - . | \
		${TAR} -xf - -C ${PREFIX}/lib/mozilla
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin

.include <bsd.port.mk>
