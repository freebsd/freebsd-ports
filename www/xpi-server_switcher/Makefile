# New ports collection makefile for:	xpi-server_switcher
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	server_switcher
PORTVERSION=	0.1b
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	An extension to navigational help tool for web developers

XPI_ID=		{F7D360DC-B8F8-11DA-86BD-3EC8728786A0}
XPI_FILES=	chrome/switcher/content/about.xul \
		chrome/switcher/content/common/preferences.js \
		chrome/switcher/content/common/string.js \
		chrome/switcher/content/dialogs/resize.js \
		chrome/switcher/content/dialogs/resize.xul \
		chrome/switcher/content/switcherOptions.js \
		chrome/switcher/content/switcherOptions.xul \
		chrome/switcher/content/switcherOverlay-old.js \
		chrome/switcher/content/switcherOverlay.js \
		chrome/switcher/content/switcherOverlay.xul \
		chrome/switcher/skin/classic/devserver.png \
		chrome/switcher/skin/classic/hceswitch.css \
		chrome/switcher/skin/classic/icon.png \
		chrome/switcher/skin/classic/liveserver.png \
		chrome.manifest install.rdf license.txt
XPI_DIRS=	chrome/switcher/content/common \
		chrome/switcher/content/dialogs chrome/switcher/content \
		chrome/switcher/skin/classic chrome/switcher/skin \
		chrome/switcher chrome

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
