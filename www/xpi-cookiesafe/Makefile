# New ports collection makefile for:	xpi-cookiesafe
# Date created:			18 April 2008
# Whom:				Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	cookiesafe
PORTVERSION=	3.0.5
DISTVERSIONSUFFIX=	-fx+tb+sm
CATEGORIES=	www

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Control cookie permissions

XPI_ID=		{9D23D0AA-D8F5-11DA-B3FC-0928ABF316DD}
XPI_NUM=	2497
XPI_FILES=	chrome/cookiesafe.jar defaults/preferences/cookiesafe.js \
		components/nsCS3rdPartyHosts.js components/nsCS3rdPartyObserver.js \
		components/nsCSCookieObserver.js components/nsCSHiddenMenuItems.js \
		components/nsCSHttpObserver.js components/nsCSLast10Hosts.js \
		components/nsCSPermManager.js components/nsCSShutdownObserver.js \
		components/nsCSTempExceptions.js components/nsCookieSafe.js \
		components/nsICS3rdPartyHosts.xpt components/nsICSHiddenMenuItems.xpt \
		components/nsICSLast10Hosts.xpt components/nsICSPermManager.xpt \
		components/nsICSTempExceptions.xpt components/nsICookieSafe.xpt \
		chrome.manifest install.js install.rdf
XPI_DIRS=	chrome components defaults/preferences defaults

post-patch:
	@${REINPLACE_CMD} -e 's|0\.7|1.*|' ${WRKSRC}/install.rdf
	@${RM} -f ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
