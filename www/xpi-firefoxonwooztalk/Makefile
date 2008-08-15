# New ports collection makefile for:	xpi-wooztalk
# Date created:		2008-06-13
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	firefoxonwooztalk
PORTVERSION=	1.1.22
CATEGORIES=	www
MASTER_SITES=	http://www.wooztalk.com/common/download/firefox/
DISTNAME=	${PORTNAME}

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors with Firefox

XPI_ID=		firefoxonwooztalk@kurioos-itech.com
XPI_FILES=	chrome.manifest install.rdf \
		content/contents.rdf content/firefoxOverlay.xul	content/overlay.js \
		locale/en-US/contents.rdf locale/en-US/firefoxonwooztalk.dtd \
		locale/en-US/firefoxonwooztalk.properties locale/fr-FR/contents.rdf \
		locale/fr-FR/firefoxonwooztalk.dtd \
		locale/fr-FR/firefoxonwooztalk.properties skin/disabled.ico \
		skin/enabled.ico skin/overlay.css skin/wooztalk.ico
XPI_DIRS=	content locale/en-US locale/fr-FR locale skin

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
