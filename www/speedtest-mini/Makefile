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
USES=		zip

do-install:
	@${MKDIR} -m 755 ${STAGEDIR}${WWWDIR}/speedtest
	${INSTALL_DATA} ${WRKDIR}/index-php.html ${STAGEDIR}${WWWDIR}/index.html
	${INSTALL_DATA} ${WRKDIR}/speedtest.swf ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/speedtest/random* \
		${STAGEDIR}${WWWDIR}/speedtest
	${INSTALL_DATA} ${WRKDIR}/speedtest/swfobject.js \
		${STAGEDIR}${WWWDIR}/speedtest
	${INSTALL_DATA} ${WRKDIR}/speedtest/upload.php \
		${STAGEDIR}${WWWDIR}/speedtest
	${CHOWN} ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
