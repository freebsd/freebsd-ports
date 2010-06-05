# New ports collection makefile for:	xpi-downthemall
# Date created:		19 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	downthemall
PORTVERSION=	1.1.10
DISTVERSIONSUFFIX=	-fx+sm
CATEGORIES=	www
MASTER_SITES=	http://releases.mozilla.org/pub/mozilla.org/addons/201/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lets you download all the links in a webpage and much more

XPI_DISTNAME=	downthemall!
WRKSRC=		${WRKDIR}/${DISTNAME:S/!/_/}

XPI_ID=		{DDC359D1-844A-42a7-9AA1-88A850A938A8}
XPI_FILES=	GPL LGPL LICENSE MPL chrome/chrome.jar \
		chrome/icons/default/DownThemAll.ico \
		chrome/icons/default/DownThemAll.xpm \
		chrome.manifest components/contentHandling.js \
		components/contenthandling.idl \
		components/contenthandling.xpt \
		components/debugService.idl components/debugService.js \
		components/debugService.xpt components/filterManager.idl \
		components/filterManager.js components/filterManager.xpt \
		components/migrationService.js components/privacycontrol.js \
		defaults/preferences/dta.js defaults/preferences/filters.js \
		defaults/preferences/privacycontrol.js install.rdf \
		modules/cothread.jsm modules/mediator.jsm \
		modules/loggedprompter.jsm \
		modules/preallocator.jsm modules/preferences.jsm \
		modules/prompts.jsm modules/utils.jsm modules/version.jsm \
		icon.png
XPI_DIRS=	chrome/icons/default chrome/icons chrome components \
		defaults/preferences defaults modules

post-extract:
	@${FIND} ${WRKSRC} -name .svn|${XARGS} ${RM} -rf

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
