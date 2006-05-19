# New ports collection makefile for:	xpi-imdbpreview
# Date created:		19 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imdbpreview
PORTVERSION=	0.2
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Preview movie & actor posters when hovering over their IMDb links

XPI_DISTNAME=	imdb_preview
XPI_ID=		{10187899-7ffe-4f9a-b9d2-35fdb3b49690}
XPI_FILES=	chrome/imdb_preview.jar chrome.manifest defaults/preferences/defaults.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
