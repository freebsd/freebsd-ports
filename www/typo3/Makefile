# New ports collection makefile for:	www/typo3
# Date created:				February 6th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	typo3
PORTVERSION=	3.8.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_src-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The typo3 content management system

NO_BUILD=	yes
USE_PHP=	mysql pcre xml session ctype
WANT_PHP_WEB=	yes

TYPO3DIR=	www/${DISTNAME}
SITEDIR?=	www/typo3
SITESRC=	${WRKDIR}/${EDITION}-${PORTVERSION}

.if defined(WITH_EDITION) && (${WITH_EDITION} == "quickstart" || ${WITH_EDITION} == "testsite")
EDITION=	${WITH_EDITION}
.else
EDITION=	dummy
.endif

.if make(makesum)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		dummy-${PORTVERSION}${EXTRACT_SUFX} \
		quickstart-${PORTVERSION}${EXTRACT_SUFX} \
		testsite-${PORTVERSION}${EXTRACT_SUFX}
.else
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${EDITION}-${PORTVERSION}${EXTRACT_SUFX}
.endif

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

# Include bsd.php.mk because use USE_PHP after bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.php.mk"

.if defined(WITH_IMAGICK)
LIB_DEPENDS+=	Magick.10:${PORTSDIR}/graphics/ImageMagick
.endif

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
