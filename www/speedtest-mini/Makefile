# Created by: Anton Grytsuk <gx@bsdplanet.ru>
# $FreeBSD$

PORTNAME=	speedtest-mini
PORTVERSION=	2.2.0
CATEGORIES=	www
MASTER_SITES=	http://c.speedtest.net/mini/
DISTNAME=	mini

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	Mini bandwidth speed test on your own server

LICENSE=	MIT

NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_ZIP=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} -m 755 ${WWWDIR}/speedtest
	@${INSTALL_DATA} ${WRKDIR}/index-php.html ${WWWDIR}/index.html
	@${INSTALL_DATA} ${WRKDIR}/speedtest.swf ${WWWDIR}
	@${INSTALL_DATA} ${WRKDIR}/speedtest/random* ${WWWDIR}/speedtest
	@${INSTALL_DATA} ${WRKDIR}/speedtest/swfobject.js ${WWWDIR}/speedtest
	@${INSTALL_DATA} ${WRKDIR}/speedtest/upload.php ${WWWDIR}/speedtest
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
