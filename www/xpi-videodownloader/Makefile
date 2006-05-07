# New ports collection makefile for:	xpi-videodownloader
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	videodownloader
PORTVERSION=	1.0
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An extension to download videos files

XPI_ID=		videodowloader@videodownloader.net
XPI_FILES=	chrome/content/viddown.js chrome/content/viddown.xul \
		chrome/skin/classic/Thumbs.db chrome/skin/classic/viddown.css \
		chrome/skin/classic/video_16x16.png \
		chrome/skin/classic/video_24x24.png \
		chrome.manifest install.rdf
XPI_DIRS=	chrome/content chrome/skin/classic chrome/skin chrome

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
