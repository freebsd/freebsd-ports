# New ports collection makefile for:	xpi-downthemall
# Date created:		19 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	downthemall
PORTVERSION=	1.1.4
DISTVERSIONSUFFIX=	-fx+tb+sm
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lets you download all the links in a webpage and much more

XPI_DISTNAME=	downthemall!
WRKSRC=		${WRKDIR}/${DISTNAME:S/!/_/}
XPI_ID=		{DDC359D1-844A-42a7-9AA1-88A850A938A8}
XPI_NUM=	201
USE_XPI=	firefox3

XPI_FILES=	components/migrationService.js \
		components/debugService.xpt \
		components/debugService.js \
		components/contenthandling.idl \
		components/filterManager.idl \
		components/contenthandling.xpt \
		components/privacycontrol.js \
		components/contentHandling.js \
		components/filterManager.xpt \
		components/filterManager.js \
		components/debugService.idl \
		LICENSE \
		GPL \
		install.rdf \
		defaults/preferences/dta.js \
		defaults/preferences/filters.js \
		defaults/preferences/privacycontrol.js \
		modules/preferences.jsm \
		modules/cothread.jsm \
		modules/utils.jsm \
		modules/mediator.jsm \
		modules/prompts.jsm \
		modules/version.jsm \
		MPL \
		chrome/icons/default/DownThemAll.xpm \
		chrome/icons/default/DownThemAll.ico \
		chrome/chrome.jar \
		chrome.manifest \
		LGPL

XPI_DIRS=	components \
		defaults/preferences \
		defaults \
		modules \
		chrome/icons/default \
		chrome/icons \
		chrome

post-extract:
	@${FIND} ${WRKSRC} -name .svn|${XARGS} ${RM} -rf

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
