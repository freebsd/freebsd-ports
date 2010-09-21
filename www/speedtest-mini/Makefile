# New ports collection makefile for:	speedtest-mini
# Date created:		2010-09-19
# Whom:			Anton Grytsuk <gx@bsdplanet.ru>
#
# $FreeBSD$
#

PORTNAME=	speedtest-mini
PORTVERSION=	2.1.5
CATEGORIES=	www
MASTER_SITES=	http://files.speedtest.ookla.com/releases/
DISTFILES=	mini${EXTRACT_SUFX}

MAINTAINER=	gx@bsdplanet.ru
COMMENT=	Mini bandwidth speed test on your own server

USE_ZIP=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}
SPEEDTEST?=	www/speedtest-mini

pre-install:

	if [ ! -f ${WRKSRC}/index-php.html ]; then ${CP} \
		${WRKSRC}/index-php.html ${WRKSRC}/index.html; fi

do-install:
	@${MKDIR} ${PREFIX}/${SPEEDTEST}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${SPEEDTEST}
	@${CHMOD} 755 ${PREFIX}/${SPEEDTEST}
	${CP} -R ${WRKSRC}/ ${PREFIX}/${SPEEDTEST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
