# New ports collection makefile for:	xpi-live_http_headers
# Date created:			29 June 2008
# Whom:				Dominic Fandrey <kamikaze@bsdforen.de>
#
# $FreeBSD$
#

PORTNAME=	live_http_headers
PORTVERSION=	0.15
DISTVERSIONSUFFIX=	-fx+sm
CATEGORIES=	www
PKGNAMEPREFIX=	xpi-

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	A firefox extension to view HTTP headers

XPI_NUM=	3829
XPI_ID=		{8f8fe09b-0bd3-4470-bc1b-8cad42b8203a}

XPI_FILES=	TODO.txt \
		chrome/icons/default/LiveHTTPHeaders.ico \
		chrome/icons/default/LiveHTTPHeaders.xpm \
		chrome/livehttpheaders.jar \
		chrome.manifest \
		components/nsHeaderInfo.js \
		defaults/preferences/prefs.js \
		install.js \
		install.rdf

XPI_DIRS=	chrome/icons/default \
		chrome/icons \
		chrome \
		components \
		defaults/preferences \
		defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
