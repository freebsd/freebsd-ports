# New ports collection makefile for:	xpi-sessionmanager
# Date created:		Sat Jun 24 21:24:19 UTC 2006
# Whom:			Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sessionmanager
PORTVERSION=	0.4.3
DISTVERSIONSUFFIX=	-fx+fl+zm
CATEGORIES=	www

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Saves and restores the state of all windows

XPI_DISTNAME=	session_manager
XPI_ID=		{1280606b-2510-4fe0-97ef-9b5a22eafe30}
XPI_FILES=	chrome/icons/default/sessionmanagerPrompt.ico \
		chrome/sessionmanager.jar \
		components/crashrecovery.js \
		components/crashrecovery.xpt \
		defaults/preferences/sessionmanager.js \
		chrome.manifest install.js install.rdf license.txt
XPI_DIRS=	chrome/icons/default chrome/icons chrome \
		components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
