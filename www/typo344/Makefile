# New ports collection makefile for:	www/typo3
# Date created:				February 6th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	typo3
PORTVERSION=	4.4.8
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}
DISTNAME=	${TYPO3EDITION}-${PORTVERSION}

MAINTAINER=	jumper99@gmx.de
COMMENT=	The typo3 content management system

LICENSE=	GPLv2

NO_LATEST_LINK=	yes
NO_BUILD=	yes
USE_PHP=	ctype filter json mysql pcre session xml
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=	4

TYPO3WWW=	www
TYPO3VER=	typo344
TYPO3SITE=	${TYPO3WWW}/${TYPO3VER}
TYPO3PKG=	${TYPO3EDITION}-${PORTVERSION}
TYPO3SRC=	typo3_src-${PORTVERSION}
TYPO3EDITION=	blankpackage

DISTFILES+=	${TYPO3EDITION}-${PORTVERSION}${EXTRACT_SUFX}

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
LIB_DEPENDS+=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif

.if defined(WITH_ZLIB)
USE_PHP+=	zlib
.endif

pre-install:
	${MV} ${WRKDIR}/${TYPO3PKG}/typo3conf/localconf.php ${WRKDIR}/${TYPO3PKG}/typo3conf/localconf.php.dist

do-install:
	${CP} -R ${WRKDIR}/${TYPO3PKG}/ ${PREFIX}/${TYPO3SITE}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3SITE}
	${MV} ${PREFIX}/${TYPO3SITE}/${TYPO3SRC} ${PREFIX}/${TYPO3WWW}
	${RM} ${PREFIX}/${TYPO3SITE}/typo3_src && \
		cd ${PREFIX}/${TYPO3SITE} && \
		${LN} -s ../${TYPO3SRC} typo3_src
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3WWW}/${TYPO3SRC}

post-install:
	@${FIND} ${PREFIX}/${TYPO3WWW}/${TYPO3SRC} -not -type d \
		| ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/${TYPO3WWW}/${TYPO3SRC} -type d \
		| ${SED} -ne 's,^${PREFIX}/${TYPO3WWW}/${TYPO3SRC},@dirrm ${TYPO3DIR}/${TYPO3WWW}/${TYPO3SRC},p' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${TYPO3SITE} -not -type d \
		| ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/${TYPO3SITE} -type d \
		| ${SED} -ne 's,^${PREFIX}/${TYPO3SITE},@dirrm ${TYPO3SITE},p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
