# New ports collection makefile for:	www/typo3
# Date created:				February 6th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	typo3
PORTVERSION=	4.5.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION} \
		http://dl1.typo3.org/TYPO3_${PORTVERSION}/
DISTNAME=	${PORTNAME}_src-${PORTVERSION}

MAINTAINER=	jumper99@gmx.de
COMMENT=	The typo3 content management system

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	ctype filter json mysql pcre session xml
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=	4

TYPO3DIR=	www/${DISTNAME}
SITEDIR?=	www/typo3
SITESRC=	${WRKDIR}/${EDITION}-${PORTVERSION}

EDITION=	dummy

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${EDITION}-${PORTVERSION}${EXTRACT_SUFX}

OPTIONS=	CURL "Configure with cURL support" off \
		GD "Configure with GDlib/freetype support" on \
		IMAGICK "Configure with ImageMagick support" on \
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
LIB_DEPENDS+=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif

.if defined(WITH_ZLIB)
USE_PHP+=	zlib
.endif

pre-install:
	${MV} ${SITESRC}/typo3conf/localconf.php ${SITESRC}/typo3conf/localconf.php.dist

do-install:
	${CP} -R ${WRKSRC} ${PREFIX}/${TYPO3DIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3DIR}
	${CP} -R ${SITESRC} ${PREFIX}/${SITEDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SITEDIR}

post-install:
	@${FIND} ${PREFIX}/${TYPO3DIR} -not -type d \
	  | ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/${TYPO3DIR} -type d \
	  | ${SED} -ne 's,^${PREFIX}/${TYPO3DIR},@dirrm ${TYPO3DIR},p' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${SITEDIR} -not -type d \
	  | ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/${SITEDIR} -type d \
	  | ${SED} -ne 's,^${PREFIX}/${SITEDIR},@dirrm ${SITEDIR},p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
