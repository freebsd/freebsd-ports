# New ports collection makefile for:	xpi-cookiesafe
# Date created:			18 April 2008
# Whom:				Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	cookiesafe
PORTVERSION=	2.0.6
DISTVERSIONSUFFIX=	-fx+fl+mz+ns+zm
CATEGORIES=	www

MAINTAINER=	ports@logvinov.com
COMMENT=	Control cookie permissions

XPI_ID=		{9D23D0AA-D8F5-11DA-B3FC-0928ABF316DD}
XPI_NUM=	2497
XPI_FILES=	chrome/cookiesafe.jar defaults/preferences/cookiesafe.js \
		chrome.manifest install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

post-patch:
	@${REINPLACE_CMD} -e 's|0\.7|1.*|' ${WRKSRC}/install.rdf
	@${RM} -f ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
