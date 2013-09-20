# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imdbpreview
DISTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/IMDb%20Preview/IMDb%20Preview%20${PORTVERSION}
DISTNAME=	IMDb_Preview_${DISTVERSION}_fixed

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Preview movie & actor posters when hovering over their IMDb links

PORTSCOUT=	skipv:0.5dev.1

XPI_ID=		{10187899-7ffe-4f9a-b9d2-35fdb3b49690}
XPI_FILES=	chrome/imdb_preview.jar chrome.manifest \
		defaults/preferences/defaults.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
