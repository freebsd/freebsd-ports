# New ports collection makefile for:	speedtest-mini
# Date created:		2010-09-19
# Whom:			Anton Grytsuk <gx@bsdplanet.ru>
#
# $FreeBSD$
#

PORTNAME=	speedtest-mini
PORTVERSION=	2.1.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://files.speedtest.ookla.com/releases/
DISTNAME=	mini

MAINTAINER=	gx@bsdplanet.ru
COMMENT=	Mini bandwidth speed test on your own server

NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_ZIP=	yes
WRKSRC=		${WRKDIR}

pre-install:
	@cd ${WRKSRC}/ && \
		${MV} pkg-message .pkg-message && \
		[ -f index-php.html ] && ${CP} index-php.html index.html \

do-install:
	${MKDIR} -m 755 ${WWWDIR}/
	${CP} -pR ${WRKSRC}/* ${WWWDIR}/
	${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${WRKSRC}/.pkg-message

.include <bsd.port.mk>
