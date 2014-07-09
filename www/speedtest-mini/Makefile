# Created by: Anton Grytsuk <gx@bsdplanet.ru>
# $FreeBSD$

PORTNAME=	speedtest-mini
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://c.speedtest.net/mini/
DISTNAME=	mini

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Mini bandwidth speed test on your own server

NO_BUILD=	yes
SUB_FILES=	pkg-message
USES=		zip

do-install:
	@${MKDIR} -m 755 ${STAGEDIR}${WWWDIR}/speedtest
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/index-php.html ${STAGEDIR}${WWWDIR}/index.html
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/speedtest.swf ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/speedtest/random* \
		${STAGEDIR}${WWWDIR}/speedtest
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/speedtest/swfobject.js \
		${STAGEDIR}${WWWDIR}/speedtest
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/speedtest/upload.php \
		${STAGEDIR}${WWWDIR}/speedtest
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
