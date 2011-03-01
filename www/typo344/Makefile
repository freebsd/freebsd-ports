# New ports collection makefile for:	www/typo3
# Date created:				February 6th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	typo3
PORTVERSION=	4.4.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}
DISTNAME=	${PORTNAME}_src-${PORTVERSION}

MAINTAINER=	jumper99@gmx.de
COMMENT=	The typo3 content management system

NO_LATEST_LINK=	yes
NO_BUILD=	yes
USE_PHP=	mysql pcre xml session ctype filter json
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=	4

LICENSE=	GPLv2

TYPO3DIR=	www/${DISTNAME}
SITEDIR?=	www/typo344
SITESRC=	${WRKDIR}/${EDITION}-${PORTVERSION}

EDITION=	dummy

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${EDITION}-${PORTVERSION}${EXTRACT_SUFX}

OPTIONS=	GD "Configure with GDlib/freetype support" off \
		ZLIB "Configure with zlib support" off \
		IMAGICK "Configure with ImageMagick support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GD)
USE_PHP+=	gd
.endif

.if defined(WITH_ZLIB)
USE_PHP+=	zlib
.endif

.if defined(WITH_IMAGICK)
LIB_DEPENDS+=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick
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
