# New ports collection makefile for:	www/typo3
# Date created:				February 6th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	typo3
PORTVERSION=	4.3.14
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}

MAINTAINER=	jumper99@gmx.de
COMMENT=	The typo3 content management system

LICENSE=	GPLv2

DEPRECATED=	Support will end in the near future, see http://typo3.org/download/packages/ for details
EXPIRATION_DATE=	2011-11-30

NO_LATEST_LINK=	yes
NO_BUILD=	yes
USE_PHP=	ctype filter json mysql pcre session xml
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=4

TYPO3WWW=	www
TYPO3RELEASE=	43
TYPO3SITE=	${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}
TYPO3PKG=	${PORTNAME}-${PORTVERSION}
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}
TYPO3DUMMY=	dummy-${PORTVERSION}

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX} ${TYPO3DUMMY}${EXTRACT_SUFX}

OPTIONS=	CURL "Configure with cURL support" off \
		GD "Configure with GDlib/freetype support" off \
		IMAGICK "Configure with ImageMagick support" off \
		MBSTRING "Configure with mbstring support" off \
		ZLIB "Configure with zlib support" off

.include <bsd.port.pre.mk>

.if defined(WITH_CURL)
USE_PHP+=	curl
.endif

.if defined(WITH_GD)
USE_PHP+=	gd
.endif

.if defined(WITH_IMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif

.if defined(WITH_ZLIB)
USE_PHP+=	zlib
.endif

pre-install:
	${MV} ${WRKDIR}/${TYPO3DUMMY}/typo3conf/localconf.php ${WRKDIR}/${TYPO3DUMMY}/typo3conf/localconf.php.dist

do-install:
	${CP} -R ${WRKDIR}/${TYPO3DUMMY}/ ${PREFIX}/${TYPO3SITE}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${PREFIX}/${TYPO3WWW}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3SITE}
	${RM} ${PREFIX}/${TYPO3SITE}/typo3_src && \
		cd ${PREFIX}/${TYPO3SITE} && \
		${LN} -s ../${TYPO3SRC} typo3_src
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3WWW}/${TYPO3SRC}

.include <bsd.port.post.mk>
