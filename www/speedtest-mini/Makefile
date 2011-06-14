# New ports collection makefile for:	speedtest-mini
# Date created:		2010-09-19
# Whom:			Anton Grytsuk <gx@bsdplanet.ru>
#
# $FreeBSD$
#

PORTNAME=	speedtest-mini
PORTVERSION=	2.1.8
CATEGORIES=	www
MASTER_SITES=	http://c.speedtest.net/mini/
DISTNAME=	mini

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	Mini bandwidth speed test on your own server

NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_ZIP=	yes

pre-install:
	@${CP} ${WRKDIR}/index-php.html ${WRKDIR}/index.html

do-install:
	@${MKDIR} -m 755 ${WWWDIR}/speedtest

	@${INSTALL_DATA} ${WRKDIR}/index.html ${WWWDIR}
	@${INSTALL_DATA} ${WRKDIR}/speedtest.swf ${WWWDIR}
	@${INSTALL_DATA} ${WRKDIR}/speedtest/random* ${WWWDIR}/speedtest
	@${INSTALL_DATA} ${WRKDIR}/speedtest/swfobject.js ${WWWDIR}/speedtest
	@${INSTALL_DATA} ${WRKDIR}/speedtest/upload.php ${WWWDIR}/speedtest

	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
